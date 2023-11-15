#ifndef MODPOW_S
#define MODPOW_S

#include <cassert>
#include <limits>
#include "modmul.hpp"
#include "general/fixed_integer.hpp"

u64 modpow_s(u64 base, u64 exponent, u64 mod) {
    assert(mod > 0);
    u64 ret = 1;
    base %= mod;
    while(exponent) {
        if (exponent&1) {
            ret = modmul(ret, base, mod);
        }
        exponent /= 2;
        base = modmul(base,base,mod);
    }
    return ret;
}

template <typename T>
T intpow(T base, T expo) {
    T INF = std::numeric_limits<T>::max();
    return modpow_s(base, expo, INF);
}

#endif 
