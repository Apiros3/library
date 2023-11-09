#line 2 "test.cpp"
#include <bits/stdc++.h>
#line 1 "numerical/factorize_s.hpp"



#line 1 "bit/ctz.hpp"



#line 1 "general/fixed_integer.hpp"



#line 5 "general/fixed_integer.hpp"
typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;


#line 5 "bit/ctz.hpp"

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


#line 1 "numerical/pollard_rho.hpp"



#line 1 "numerical/gcd.hpp"



#line 5 "numerical/gcd.hpp"

template<typename T>
T gcd(T a, T b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}


#line 1 "numerical/modmul.hpp"



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


#line 1 "numerical/miller_rabin.hpp"



#line 1 "numerical/modpow_s.hpp"



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


#line 8 "numerical/pollard_rho.hpp"

//tries to find a factor with probabilistic measures

template <typename T>
T find_prime_factor(T num) {
    if (num%2 == 0) {
        return 2;
    }
    T mx = 1ll + pow(num,0.125);

    for(T c = 1; c < num; c++) {
        auto f = [&](T a) {
            return (T)((modmul(a,a,num) + c)%num); 
        };
        T x = 0, y = 0, g = 1;
        while(g == 1) {
            x = f(x);
            y = f(f(y));
            g = gcd(std::abs(x-y), num);
        }
        if (g == num) continue;
        if (Miller::isPrime(g)) {
            return g;
        }
        else if (Miller::isPrime(num/g)) {
            return num/g;
        }
        else {
            return find_prime_factor(g);
        }
    }
    return num;
}



#line 7 "numerical/factorize_s.hpp"

//pollard rho factorization
template<typename T>
std::vector<std::pair<T,i32>> factorize_s(T num) {
    std::vector<std::pair<T,i32>> ret;
    i32 tmp = ctz(num);
    if (tmp != 0) {
        ret.emplace_back(2,tmp);
    }
    num >>= tmp;
    while(Miller::isPrime(num) == 0 && num != 1) {
        T min_fact = find_prime_factor(num);
        i32 cnt = 0;
        while(num%min_fact == 0) {
            num /= min_fact;
            cnt++;
        }
        ret.emplace_back(min_fact,cnt);
    }
    if (num != 1) {
        ret.emplace_back(num,1);
    }
    sort(ret.begin(),ret.end());

    return ret;
}



#line 4 "test.cpp"
using namespace std;
using ll = long long;

int main() {
    
    ll Q; cin >> Q;
    while(Q--) {
        ll N; cin >> N;
        auto tmp = factorize_s(N);
        ll sum = 0;
        for(auto [u,v] : tmp) {
            sum += v;
        }
        cout << sum << " ";
        for(auto [u,v] : tmp) {
            for(int i = 0; i < v; i++) cout << u << " ";
        }
        cout << endl;

    }

    return 0;
}
