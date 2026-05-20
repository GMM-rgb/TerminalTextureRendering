#pragma once
#include <iostream>
/// @brief
/// @details
#define TYPE_VALID(value, T) \
    ([]() -> bool { return std::is_same_v<decltype(value), T>; }())
