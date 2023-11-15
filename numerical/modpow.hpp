#ifndef MODPOW
#define MODPOW

#include <iostream>
#include "general/fixed_integer.hpp"


template <typename T>
T modpow(T base, T expo, T mod) {
    T ret = 1%mod;
    base %= mod;
    for(; topn; topn /= 2, btmn = (btmn*btmn)%mod) 
        if (topn & 1) ret = (ret*btmn)%mod; 
    return ret;
}


#endif 