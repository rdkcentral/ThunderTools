#!/usr/bin/env python3

# If not stated otherwise in this file or this component's license file the
# following copyright and licenses apply:
#
# Copyright 2020 Metrological
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse
import sys
import os
import subprocess
import shutil
import time
import re
from git import Repo

sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir))

import ProxyStubGenerator.Log as Log

NAME = "DocumentGenerator"
VERBOSE = True
SHOW_WARNINGS = True
DOC_ISSUES = False
log = Log.Log(NAME, VERBOSE, SHOW_WARNINGS, DOC_ISSUES)

SITE_NAME = "Documentation"
SITE_URL = "https://webplatformforembedded.github.io/ServicesInterfaceDocumentation/"

DOCS_REPO_URL = "git@github.com:WebPlatformForEmbedded/ServicesInterfaceDocumentation.git"
THUNDER_REPO_URL = "https://github.com/rdkcentral/Thunder"
THUNDER_TOOLS_REPO_URL = "https://github.com/rdkcentral/ThunderTools"
THUNDER_INTERFACE_REPO_URL = "https://github.com/rdkcentral/ThunderInterfaces"
THUNDER_PLUGINS_REPO_URL = "https://github.com/rdkcentral/ThunderNanoServices.git"
RDK_PLUGINS_REPO_URL = "https://github.com/WebPlatformForEmbedded/ThunderNanoServicesRDK.git"

VERSION_PATTERN = re.compile(r'^R\d+\.\d+(?:\.\d+)?$')


class MkdocsYamlFileGenerator():
    def __init__(self, docs_path, site_name, site_url):
        self._yamlfile_path = os.path.join(docs_path, "mkdocs.yml")
        self._site_name = site_name
        self._site_url = site_url
        self._current_topic = ""
        self._topic_dict = {}
        self._fd = None

    def create_site_details(self):
        assert self._fd is not None
        self._fd.write("site_name : " + self._site_name + "\n")
        self._fd.write("site_url : " + self._site_url + "\n")

    def add_nav_tag(self):
        assert self._fd is not None
        self._fd.write("nav:\n    - 'Home': 'index.md'\n")

    def add_topic(self, topic_name):
        assert self._fd is not None
        self._fd.write("    - '" + topic_name + "':\n")

    def add_subtopic(self, sub_topic_name, markdown_filename):
        assert self._fd is not None
        self._fd.write("        - '" + sub_topic_name + "' : '" + markdown_filename + "'\n")

    def create_topics(self, topic_name):
        if topic_name not in self._topic_dict.keys():
            self._topic_dict[topic_name] = []
        self._current_topic = topic_name

    def create_subtopics(self, sub_topic_name, markdown_filename):
        if self._topic_dict[self._current_topic] is not None and isinstance(self._topic_dict[self._current_topic], list):
            self._topic_dict[self._current_topic].append((sub_topic_name, markdown_filename))

    def create_file(self):
        self._fd = open(self._yamlfile_path, "w")
        self.create_site_details()
        self.add_theme_info()
        self.add_nav_tag()
        for topic in self._topic_dict:
            self.add_topic(topic)
            for subtopic in self._topic_dict[topic]:
                self.add_subtopic(subtopic[0], subtopic[1])
        self._fd.close()
        self._fd = None
        log.Info("Created %s" % self._yamlfile_path)

    def add_theme_info(self):
        assert self._fd is not None
        theme_info = '''
extra:
    version:
        provider: mike

theme:
    name: material
    highlightjs: true
    custom_dir: overrides

markdown_extensions:
    - attr_list
    - pymdownx.emoji:
        emoji_index: !!python/name:material.extensions.emoji.twemoji
        emoji_generator: !!python/name:material.extensions.emoji.to_svg'''

        self._fd.write(theme_info + "\n")


class DocumentGenerator:
    def __init__(self, thunder_path, thunder_interface_path, thunder_plugins_path, rdk_plugins_path,
                 thunder_tools_path, docs_path, local_tools=False):
        self._local_tools = local_tools
        self.thunder_path = thunder_path
        self.thunder_tools_path = thunder_tools_path
        self.thunder_interface_path = thunder_interface_path
        self.thunder_plugins_path = thunder_plugins_path
        self.rdk_plugins_path = rdk_plugins_path
        self.docs_path = docs_path
        self.is_branch_name_valid()
        self.clean_all_repos_dir()
        self.clone_all_repos()
        self._yaml_generator = MkdocsYamlFileGenerator(docs_path=self.docs_path, site_name=SITE_NAME, site_url=SITE_URL)
        self.mkdocs_create_index_file()

    @staticmethod
    def is_branch_name_valid():
        if not VERSION_PATTERN.fullmatch(branch_name):
            log.Error("Branch name must be whether RX.X or RX.X.X where X represents semantic versioning "
                      "for major.minor or major.minor.patch)")
            sys.exit()

    def clean_all_repos_dir(self):
        if os.path.exists(self.thunder_path):
            shutil.rmtree(self.thunder_path)
        if os.path.exists(self.thunder_interface_path):
            shutil.rmtree(self.thunder_interface_path)
        if os.path.exists(self.thunder_plugins_path):
            shutil.rmtree(self.thunder_plugins_path)
        if os.path.exists(self.rdk_plugins_path):
            shutil.rmtree(self.rdk_plugins_path)
        if os.path.exists(self.docs_path):
            shutil.rmtree(self.docs_path)
        if not self._local_tools and os.path.exists(self.thunder_tools_path):
            shutil.rmtree(self.thunder_tools_path)

    def clone_all_repos(self):
        self.docs_commit_id, self.docs_commit_date = self.clone_repo(DOCS_REPO_URL, self.docs_path)
        self.thunder_commit_id, self.thunder_commit_date = self.clone_repo(THUNDER_REPO_URL, self.thunder_path)
        self.thunder_interfaces_commit_id, self.thunder_interfaces_commit_date = self.clone_repo(THUNDER_INTERFACE_REPO_URL, self.thunder_interface_path)
        self.thunder_plugins_commit_id, self.thunder_plugins_commit_date = self.clone_repo(THUNDER_PLUGINS_REPO_URL, self.thunder_plugins_path)
        self.rdk_plugins_commit_id, self.rdk_plugins_commit_date = self.clone_repo(RDK_PLUGINS_REPO_URL, self.rdk_plugins_path)

        if not self._local_tools:
            self.thunder_tools_commit_id, self.thunder_tools_commit_date = self.clone_repo(THUNDER_TOOLS_REPO_URL, self.thunder_tools_path)

    @staticmethod
    def clone_repo(repo_url, local_path):
        if repo_url == DOCS_REPO_URL:
            repo = Repo.clone_from(repo_url, local_path, branch="gh-pages")

        else:
            # Change . with _ as we use underscore for branch names
            _branch_name = branch_name
            _branch_name = branch_name.replace('.', '_')

            repo = Repo.clone_from(repo_url, local_path, branch=_branch_name, depth=1)

        headcommit = repo.head.commit
        headcommit_sha = headcommit.hexsha
        headcommit_date = time.strftime("%a, %d %b %Y %H:%M", time.gmtime(headcommit.committed_date))
        log.Info("Repo {}".format(repo_url))
        log.Info("Repo head: {}".format(headcommit.hexsha))
        log.Info("Repo commit date: {}".format(headcommit_date))
        return headcommit_sha, headcommit_date

    def mkdocs_create_index_file(self):
        if not os.path.exists(os.path.join(self.docs_path, "docs")):
            os.mkdir(os.path.join(self.docs_path, "docs"))

        index_file = open(os.path.join(self.docs_path, "docs", "index.md"), "w")

        index_file_thunder_contents = (("# Welcome to Documentation\nThese documentation are automatically created "
                                       "using mkdocs on ") + time.strftime("%a, %d %b %Y %H:%M", time.gmtime())
                                       + " GMT\n\
## Thunder\nThis section contains the documentation created from Thunder\n\n\
| Repo | Commit-Id | Commit-Date |\n\
| :--- | :-------- | :---------- |\n\
|[Thunder](" + THUNDER_REPO_URL + ')|' + self.thunder_commit_id + '|' + self.thunder_commit_date + " GMT|\n\n")

        index_file_interface_contents = (("## Interfaces\nThis section contains the documentation created from "
                                         "interfaces\n\n\
| Repo | Commit-Id | Commit-Date |\n\
| :--- | :-------- | :---------- |\n\
|[ThunderInterfaces](") + THUNDER_INTERFACE_REPO_URL + ')|' + self.thunder_interfaces_commit_id + '|'
                                         + self.thunder_interfaces_commit_date + " GMT|\n\n")

        index_file_contents_plugins = ('''## Plugins\nThis section contains the documentation created from plugins\n\n\
| Repo | Commit-Id | Commit-Date |\n\
| :--- | :-------- | :---------- |\n\
| [ThunderNanoServices]('''+THUNDER_PLUGINS_REPO_URL + ') | ' + self.thunder_plugins_commit_id + ' | ' +
                                       self.thunder_plugins_commit_date + " GMT |\n| [ThunderNanoServicesRDK](" +
                                       RDK_PLUGINS_REPO_URL + ') | ' + self.rdk_plugins_commit_id + ' | ' +
                                       self.rdk_plugins_commit_date + " GMT |\n")
        
        index_file.write(index_file_thunder_contents)
        index_file.write(index_file_interface_contents)
        index_file.write(index_file_contents_plugins)

    def add_topic(self, topic_name, path):
        base = os.path.basename(path)
        self._yaml_generator.create_topics(topic_name)

        files = os.listdir(path)

        if files:
            files.sort(key=str.casefold)

        for f in files:
            if os.path.isfile(os.path.join(path, f)) and f != "index.md":
                with open(os.path.join(path, f)) as ff:
                    lines = ff.readlines()
                    if lines[2][0] == '#':
                        title = lines[2][1:].strip()
                        self._yaml_generator.create_subtopics(title, os.path.join(base, f))

    @staticmethod
    def to_markdown(md_path, include_dirs, cpp_interface_dir, json_interface_dir, paths, ns=None):
        cmd = [os.path.join(".", "JsonGenerator.py"), "--docs", "--output", md_path]

        if json_interface_dir:
            cmd.extend(["-i", json_interface_dir])

        if cpp_interface_dir:
            cmd.extend(["-j", cpp_interface_dir])

        if ns:
            cmd.extend(["--namespace", ns])

        cmd.append("--verbose")

        cmd.extend(paths)

        for i in include_dirs:
            cmd.extend(["-I", i])

        ret_val = subprocess.run(cmd)
        log.Info("JsonGenerator exit code: {} ".format(ret_val.returncode))

    def complete_yaml_creation(self):
        self._yaml_generator.create_file()


if __name__ == "__main__":
    argparser = argparse.ArgumentParser(
        description='Generate API and plugin documentation.',
        formatter_class=argparse.RawTextHelpFormatter)

    docs_repo_url = os.environ.get("DOCS_REPO_URL")
    if docs_repo_url is not None:
        DOCS_REPO_URL = docs_repo_url

    argparser.add_argument("--deploy",
                           dest="github_deploy",
                           action="store_true",
                           default=False,
                           help="Deploy generated code in GitHub")

    argparser.add_argument("--clone_path",
                           dest="clone_path",
                           action="store",
                           type=str,
                           metavar="DIR",
                           required=True,
                           help="Local path for cloning necessary repositories")

    argparser.add_argument("--branch",
                           dest="branch_name",
                           action="store",
                           required=True,
                           help="Branch name for repositories")

    argparser.add_argument("--tag",
                           dest="tag",
                           action="store",
                           help="Tag for documents. ie: latest, dev, stable")

    argparser.add_argument("--local-tools",
                           dest="local_tools",
                           action="store_true",
                           default=False,
                           help="Use local tools instead of fetching them from the branch")

    args = argparser.parse_args(sys.argv[1:])

    clone_path = args.clone_path
    deploy_docs = args.github_deploy
    branch_name = args.branch_name
    tag = args.tag

    thunder_interface_path = os.path.join(clone_path, "thunder_interfaces")
    thunder_plugins_path = os.path.join(clone_path, "thunder_nano_services")
    rdk_plugins_path = os.path.join(clone_path, "thunder_nano_services_rdk")
    thunder_path = os.path.join(clone_path, "thunder")
    controller_plugins_path = os.path.join(thunder_path, "Source", "Thunder")
    docs_path = os.path.join(clone_path, "Documentation")

    if args.local_tools:
        thunder_tools_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
    else:
        thunder_tools_path = os.path.join(clone_path, "thunder_tools")

    log.Info("Branch: {}".format(branch_name))
    log.Info("Thunder path: {}".format(thunder_path))
    log.Info("Interface path: {}".format(thunder_interface_path))
    log.Info("NanoServices path: {}".format(thunder_plugins_path))
    log.Info("RDK NanoServices path: {}".format(rdk_plugins_path))
    log.Info("Thunder Tools path: {}".format(thunder_tools_path))
    log.Info("Documentation path: {}".format(docs_path))

    document_generator = DocumentGenerator(thunder_path, thunder_interface_path, thunder_plugins_path, rdk_plugins_path, thunder_tools_path, docs_path, args.local_tools)
    os.chdir(os.path.join(thunder_tools_path, "JsonGenerator"))

    include_dirs = [os.path.join(thunder_path, "Source")]
    cpp_interfaces = os.path.join(thunder_interface_path, "interfaces")
    json_interfaces = os.path.join(thunder_interface_path, "jsonrpc")
    controller_interfaces = os.path.join(thunder_path, "Source", "plugins")
    md_path = os.path.join(docs_path, "docs")

    controller_namespace = "Thunder::Exchange::Controller"

    log.Info("Adding Thunder Documentation")
    topic = os.path.join(md_path, "thunder")
    document_generator.to_markdown(topic, include_dirs, controller_interfaces, None, [os.path.join(controller_plugins_path, "*Plugin.json")], controller_namespace)
    document_generator.add_topic("Thunder", topic)

    log.Info("Adding Interface Documentation")
    topic = os.path.join(md_path, "api")
    document_generator.to_markdown(topic, include_dirs, cpp_interfaces, json_interfaces,
                                   [os.path.join(cpp_interfaces, "*.h"), os.path.join(json_interfaces, "*.json")])
    document_generator.add_topic("Interfaces", topic)

    log.Info("Adding Plugin Documentation")
    topic = os.path.join(md_path, "plugins")
    document_generator.to_markdown(topic, include_dirs, cpp_interfaces, json_interfaces, [os.path.join(thunder_plugins_path, "*", "*Plugin.json")])
    document_generator.to_markdown(topic, include_dirs, cpp_interfaces, json_interfaces, [os.path.join(rdk_plugins_path, "*", "*Plugin.json")])
    document_generator.add_topic("Plugins", topic)

    document_generator.complete_yaml_creation()

    if deploy_docs:

        try:
            # unless DOCS_REPO_URL is changed the documentation will be deployed in this location:
            # https://webplatformforembedded.github.io/ServicesInterfaceDocumentation/
            commands = ["mike", "deploy", branch_name, "-p"]
            if tag:
                cmd = tag, "-u"
                commands.extend(cmd)
                
            os.chdir(docs_path)
            ret_val = subprocess.run(commands)
            log.Info("mkdocs exit code: {} ".format(ret_val.returncode))

        except subprocess.CalledProcessError as err:
            log.Error("Error in creating docs: {}".format(str(err)))


