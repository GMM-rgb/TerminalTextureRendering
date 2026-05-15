/// @include Project Internals
#include "./../headers/CHECKSUM_TYPES.hpp"
/// @include Core Internals & Externals
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

namespace TexturePlainImporting {
    class FileImportOperation {
        private:
            
        public:
            /// @property
            char *FetchedFileContents;
            /// @brief 
            inline FileImportOperation() {
                
            }

            inline const bool isFileImported() {
                const bool imported = this->FetchedFileContents != nullptr;
                return (bool) 0;
            }
    };

    inline bool CheckFileURL() {
        const char FilePatternURL = \
        * (std::string::const_pointer(""));
        // std::to_string(*FilePatternURL);
        return (bool)(0);
    }

    inline const auto ImportTextureFile(const std::string TextureFileLocation) {
        const bool isFileLocation = CheckFileURL();
        std::cout << TYPE_VALID(isFileLocation, bool) << std::endl;
        const auto ImportOperation = new FileImportOperation();
        // ImportOperation->FetchedFileContents;
        return nullptr;
    }
}
