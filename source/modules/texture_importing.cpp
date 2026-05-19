/// @include Project Internals
#include "./../headers/CHECKSUM_TYPES.hpp"
#include "./../headers/hcp.hpp"
/// @include Core Internals & Externals
#include <fstream>
#include <filesystem>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <regex>
/// @include
#include <math.h>

using namespace std;
using namespace std::filesystem;

namespace TexturePlainImporting {
    FileImportOperation::FileImportOperation(const std::string *TextureFileURL) {
        if (TextureFileURL != nullptr && TYPE_VALID(TextureFileURL, std::string)) {
            const filesystem::path ComposedFilePath = "/";
            // filesystem::exists();
        }
    }

    inline bool CheckFileURL() {
        const char FilePatternURL = *(std::string::const_pointer(""));
        return ((bool)(0));
    }

    inline const auto ImportTextureFile(const std::string *TextureFileLocation) {
        const bool isFileLocation = CheckFileURL();
        const auto ImportOperation =
            TYPE_VALID(isFileLocation, bool)
                ? new FileImportOperation(TextureFileLocation)
                : nullptr;

        std::cout << "Texture File URL:\t" + *TextureFileLocation << endl;
        std::cout << "Location Texture File URL VALID:\t" << TYPE_VALID(isFileLocation, bool) << endl;

        if (ImportOperation->isFileImported() && ImportOperation->FetchedFileContents != nullptr) {
            
        }

        return nullptr;
    }
} // namespace TexturePlainImporting
