#include <iostream>
#include <thread>

#define TYPE_VALID(value, T) \
    ([]() -> bool { return std::is_same_v<decltype(value), T>; }())
