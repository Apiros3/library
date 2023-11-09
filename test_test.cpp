#line 1 "numerical/miller_rabin.hpp"



#line 1 "general/fixed_integer.hpp"



#include <stdint.h>
typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;


#line 1 "numerical/modmul.hpp"



#include <iostream>
#line 6 "numerical/modmul.hpp"

typedef long double ld;

/**
 * reference: https://github.com/kth-competitive-programming/kactl/blob/main/doc/modmul-proof.md
*/

//returns a*b mod M (for M in uint64_t)
u64 modmul(u64 a, u64 b, u64 mod) {
    i64 ret = a * b - mod * (u64)(ld(a) * ld(b) / ld(mod));
    return ret + mod * (ret < 0) - mod * (ret >= (i64)mod);
}


#line 1 "numerical/modpow_s.hpp"



#include <cassert>
#line 7 "numerical/modpow_s.hpp"


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


#line 7 "numerical/miller_rabin.hpp"

namespace Miller {
    bool isPrime(u64 n) {
        if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
        u64 A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n-1), d = n >> s;
        for (u64 a : A) {
            u64 p = modpow_s(a%n, d, n), i = s;
            while (p != 1 && p != n - 1 && a % n && i--)
                p = modmul(p,p,n);
            if (p != n-1 && i != s) return 0;
        }
        return 1;
    }
}


#line 3 "test.cpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll Q; cin >> Q;
    while(Q--) {
        ll N; cin >> N;
        cout << (Miller::isPrime(N) ? "Yes" : "No") << endl;
    }
    
    return 0;
}
