#ifndef MODMUL
#define MODMUL

#include <iostream>
#include "general/fixed_integer.hpp"

typedef long double ld;

/**
 * reference: https://github.com/kth-competitive-programming/kactl/blob/main/doc/modmul-proof.md
*/

//returns a*b mod M (for M in uint64_t)
u64 modmul(u64 a, u64 b, u64 mod) {
    i64 ret = a * b - mod * (u64)(ld(a) * ld(b) / ld(mod));
    return ret + mod * (ret < 0) - mod * (ret >= (i64)mod);
}

#endif 