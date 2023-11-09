#ifndef CTZ 
#define CTZ

#include "general/fixed_integer.hpp"

/**
 * reference https://github.com/shino16/cpp-library/blob/main/bit/ctz.hpp 
 * 
 */

template <typename T>
i32 ctz(T num) {
    if (!num) {
        return sizeof(T) * 8;
    }
    if constexpr (sizeof(T) <= sizeof(unsigned)) {
        return __builtin_ctz((unsigned)num);
    } 
    else if constexpr (sizeof(T) <= sizeof(unsigned long long)) {
        return __builtin_ctz((unsigned long long)num);
    }
    else if constexpr (sizeof(T) <= sizeof(unsigned long long) * 2) {
        unsigned long long y = num;
        return y ? ctz(y)
            : sizeof(y) * 8 + ctz((unsigned long long)(num >> sizeof(y) * 8));
    }
}

#endif