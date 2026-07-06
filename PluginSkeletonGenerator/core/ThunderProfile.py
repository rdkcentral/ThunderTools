'''
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
'''

from dataclasses import dataclass
from typing import Dict


@dataclass(frozen=True)
class ThunderProfile:
    name: str
    version: str
    framework_namespace: str
    cmake_package: str
    library_prefix: str
    sink_type: str
    remote_connection_revocation_method: str
    remote_connection_noop_methods: tuple


PROFILES: Dict[str, ThunderProfile] = {
    "4": ThunderProfile(
        name="thunder4",
        version="4",
        framework_namespace="WPEFramework",
        cmake_package="WPEFramework",
        library_prefix="WPEFramework",
        sink_type="Core::Sink",
        remote_connection_revocation_method="Dangling",
        remote_connection_noop_methods=("Revoked",),
    ),
    "5": ThunderProfile(
        name="thunder5",
        version="5",
        framework_namespace="Thunder",
        cmake_package="Thunder",
        library_prefix="Thunder",
        sink_type="Core::SinkType",
        remote_connection_revocation_method="Dangling",
        remote_connection_noop_methods=(),
    ),
}

DEFAULT_PROFILE = PROFILES["4"]


def profile_for_version(version: str) -> ThunderProfile:
    normalized = str(version or DEFAULT_PROFILE.version).strip()
    if normalized not in PROFILES:
        supported = ", ".join(sorted(PROFILES.keys()))
        raise ValueError(f"Unsupported Thunder version '{version}'. Supported versions: {supported}")
    return PROFILES[normalized]