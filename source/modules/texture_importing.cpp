/// @include Project Internals
#include "./../headers/CHECKSUM_TYPES.hpp"
/// @include Core Internals & Externals
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>

namespace TexturePlainImporting {
    class FileImportOperation {
        private:
            
        public:
        /// @property
        char *FetchedFileContents = nullptr;
        /// @brief 
        FileImportOperation(std::string TextureFilePathingURL) {
            std::filesystem::current_path(std::filesystem::path(std::string("./")));
        }

        const bool isFileImported() {
            const bool imported = this->FetchedFileContents != nullptr;
            return (bool) 0;
        }
    };

    inline bool CheckFileURL() {
        const char FilePatternURL = * \
        (std::string::const_pointer(""));
        return ((bool)(0));
    }

    inline const auto ImportTextureFile(const std::string TextureFileLocation) {
        const bool isFileLocation = CheckFileURL();
        const auto ImportOperation = \
        TYPE_VALID(isFileLocation, bool) ? \
        new FileImportOperation(TextureFileLocation) : nullptr;

        std::cout << "Location Texture File URL:\t" << TYPE_VALID(isFileLocation, bool) << std::endl;

        if (ImportOperation->isFileImported() && ImportOperation->FetchedFileContents != nullptr) {

        }

        return nullptr;
    }
}
