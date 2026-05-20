/// @include
#include "./source/headers/hcp.hpp"
/// @include
#include <iostream>
#include <string>

using namespace std;
using namespace TexturePlainImporting;

int main() {
    std::string *ExitInput = nullptr;

    // new TexturePlainImporting::FileImportOperation();

    do {
        std::cin >> *ExitInput;
        std::getline(std::cin, *ExitInput);
    } while (*ExitInput != std::string("\n"));

    return 0;
}
