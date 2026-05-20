/// @include
#include "./source/headers/global/hcp.hpp"
/// @include
#include <iostream>
#include <string>
/// @protocol
using namespace std;
using namespace TexturePlainImporting;
using namespace TaskManagmentThreading;
using typename TaskManagmentThreading::ThreadInstancingOperation;

int main() {
    std::string *ExitInput = nullptr;

    // ThreadInstancingOperation;
    // ThreadInstancingOperation::ThreadInstancingOperation;
    // new TexturePlainImporting::FileImportOperation();

    do {
        std::cin >> *ExitInput;
        std::getline(std::cin, *ExitInput);
    } while (*ExitInput != std::string("\n"));

    return 0;
}
