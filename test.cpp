#include "./source/headers/CHECKSUM_TYPES.hpp"
#include "./source/headers/TEXTURE_IMPORTS.hpp"

#include <iostream>
#include <string>

int main() {
    std::string *ExitInput = nullptr;
    new TexturePlainImporting::FileImportOperation("/");
    /// @brief
    do {
        std::cin >> *ExitInput;
        std::getline(std::cin, *ExitInput);
    } while (*ExitInput != std::string("\n"));
    
    return 0;
}
