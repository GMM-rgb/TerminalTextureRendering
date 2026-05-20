/// @include Project Internals
#include "./../headers/CHECKSUM_TYPES.hpp"
#include "./../headers/global/hcp.hpp"
/// @include Core Internals & Externals
#include <fstream>
#include <filesystem>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <regex>
// #include <sandbox.h>
#include <math.h>
/// @typedef
using namespace std;
using namespace std::literals;
using namespace std::filesystem;
using namespace std::regex_constants;
using typename  std::regex;
using typename std::string;

namespace TexturePlainImporting {
    /// @brief 
    /// @param TextureFileURL 
    inline FileImportOperation::FileImportOperation(std::string *TextureFileURL) {
        if (TextureFileURL != nullptr && TYPE_VALID(TextureFileURL, std::string)) {
            const filesystem::path ComposedFilePath = string::pointer(TextureFileURL->data());
            const bool TextureFilePathValid = ((bool) is_directory(ComposedFilePath) ? 1 : 0);
            std::cout << "Texture File Found:\t" << std::string::const_pointer(TextureFilePathValid) << std::endl;
            const auto DestinationCorrectionReference = std::regex("/./", regex_constants::icase && regex_constants::grep);
            const auto CorrectionLocaleReference = DestinationCorrectionReference.getloc().global(locale::classic());
            const bool FileDestinationCorrection = regex_search(string::pointer(TextureFileURL), DestinationCorrectionReference);
        }
    }

    inline bool CheckFileURL() {
        const char FilePatternURL = *(std::string::const_pointer(""));
        return ((bool)(0));
    }

    inline const auto ImportTextureFile(std::string *TextureFileLocation) {
        if (TextureFileLocation != nullptr) {
            const bool isFileLocation = CheckFileURL();
            const auto ImportOperation =
                TYPE_VALID(isFileLocation, bool)
                    ? new FileImportOperation(TextureFileLocation)
                    : nullptr;

            std::cout << "Texture File URL:\t" + *TextureFileLocation << endl;
            std::cout << "Location Texture File URL VALID:\t" << TYPE_VALID(isFileLocation, bool) << endl;

            if (ImportOperation->isFileImported() && ImportOperation->FetchedFileContents != nullptr) {
                
            }
        }

        return nullptr;
    }
} // namespace TexturePlainImporting
