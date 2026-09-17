// C++ types for Butler API.
// Generated automatically from 'IButler.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IButler.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Butler {

        // Common classes
        //

        class AddedParamsInfo : public Core::JSON::Container {
        public:
            AddedParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("element"), &Element);
            }

            AddedParamsInfo(const AddedParamsInfo&) = delete;
            AddedParamsInfo(AddedParamsInfo&&) noexcept  = delete;

            AddedParamsInfo& operator=(const AddedParamsInfo&) = delete;
            AddedParamsInfo& operator=(AddedParamsInfo&&) noexcept  = delete;

            ~AddedParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Element.IsSet() == true);
            }

        public:
            Core::JSON::String Element;
        }; // class AddedParamsInfo

        class BranchParamsInfo : public Core::JSON::Container {
        public:
            BranchParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("path"), &Path);
            }

            BranchParamsInfo(const BranchParamsInfo&) = delete;
            BranchParamsInfo(BranchParamsInfo&&) noexcept  = delete;

            BranchParamsInfo& operator=(const BranchParamsInfo&) = delete;
            BranchParamsInfo& operator=(BranchParamsInfo&&) noexcept  = delete;

            ~BranchParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Path.IsSet() == true);
            }

        public:
            Core::JSON::String Path;
        }; // class BranchParamsInfo

        class IdentifierParamsInfo : public Core::JSON::Container {
        public:
            IdentifierParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("id"), &Id);
            }

            IdentifierParamsInfo(const IdentifierParamsInfo&) = delete;
            IdentifierParamsInfo(IdentifierParamsInfo&&) noexcept  = delete;

            IdentifierParamsInfo& operator=(const IdentifierParamsInfo&) = delete;
            IdentifierParamsInfo& operator=(IdentifierParamsInfo&&) noexcept  = delete;

            ~IdentifierParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Id.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Id;
        }; // class IdentifierParamsInfo

        // Method params/result classes
        //

        class LinkParamsData : public Core::JSON::Container {
        public:
            LinkParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
                Add(_T("id"), &Id);
            }

            LinkParamsData(const LinkParamsData&) = delete;
            LinkParamsData(LinkParamsData&&) noexcept  = delete;

            LinkParamsData& operator=(const LinkParamsData&) = delete;
            LinkParamsData& operator=(LinkParamsData&&) noexcept  = delete;

            ~LinkParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Name.IsSet() == true) && (Id.IsSet() == true));
            }

        public:
            Core::JSON::String Name;
            Core::JSON::DecUInt32 Id;
        }; // class LinkParamsData

        class MoveParamsData : public Core::JSON::Container {
        public:
            MoveParamsData()
                : Core::JSON::Container()
            {
                Add(_T("path"), &Path);
                Add(_T("newName"), &NewName);
            }

            MoveParamsData(const MoveParamsData&) = delete;
            MoveParamsData(MoveParamsData&&) noexcept  = delete;

            MoveParamsData& operator=(const MoveParamsData&) = delete;
            MoveParamsData& operator=(MoveParamsData&&) noexcept  = delete;

            ~MoveParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Path.IsSet() == true) && (NewName.IsSet() == true));
            }

        public:
            Core::JSON::String Path;
            Core::JSON::String NewName;
        }; // class MoveParamsData

        class NameParamsData : public Core::JSON::Container {
        public:
            NameParamsData()
                : Core::JSON::Container()
            {
                Add(_T("name"), &Name);
            }

            NameParamsData(const NameParamsData&) = delete;
            NameParamsData(NameParamsData&&) noexcept  = delete;

            NameParamsData& operator=(const NameParamsData&) = delete;
            NameParamsData& operator=(NameParamsData&&) noexcept  = delete;

            ~NameParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        public:
            Core::JSON::String Name;
        }; // class NameParamsData

        class OrphansParamsData : public Core::JSON::Container {
        public:
            OrphansParamsData()
                : Core::JSON::Container()
            {
                Add(_T("module"), &Module);
            }

            OrphansParamsData(const OrphansParamsData&) = delete;
            OrphansParamsData(OrphansParamsData&&) noexcept  = delete;

            OrphansParamsData& operator=(const OrphansParamsData&) = delete;
            OrphansParamsData& operator=(OrphansParamsData&&) noexcept  = delete;

            ~OrphansParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Module.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt8 Module;
        }; // class OrphansParamsData

    } // namespace Butler

    POP_WARNING()

} // namespace JsonData

}

