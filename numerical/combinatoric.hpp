#ifndef COMBINATORIC 
#define COMBINATORIC

#include <vector>
#include "mint.hpp"

//fixed mod 
template<i64 mod> class combinatoric {
private:
    using mint = modint<mod>;
    std::vector<mint> fact, inv, ivfact;
    i64 size = 2;

public:
    void update(i64 newsize) {
        if (newsize+1 <= size) return;
        fact.resize(newsize+1);
        inv.resize(newsize+1);
        ivfact.resize(newsize+1);
        for(i32 i = size; i <= newsize; i++) {
            fact[i] = fact[i-1] * i;
            inv[i] = -(inv[mod%i] * (mod/i));
            ivfact[i] = ivfact[i-1] * inv[i];
        }
    }
    combinatoric() : fact(2,1), inv(2,1), ivfact(2,1) {}

    mint nCr(i64 N, i64 R) {
        if (N < R)  return 0;
        if (N < 0 || R < 0) return 0;
        update(N);
        return fact[N] * ivfact[R] * ivfact[N-R];
    }
    mint nPr(i64 N, i64 R) {
        if (N < R)  return 0;
        if (N < 0 || R < 0) return 0;
        update(N);
        return fact[N] * ivfact[N-R];
    }
    mint nHm(i64 N, i64 M) {
        return nCr(N+M-1,M);        
    }
};

//mod not fixed (given as input) for prime mod
template <typename T>
class combinatoric_s {
private:
    std::vector<T> fact, inv, ivfact;
    T mod;
    i64 size = 2;
    void update(i64 newsize) {
        if (newsize+1 <= size) return;
        fact.resize(newsize+1);
        inv.resize(newsize+1);
        ivfact.resize(newsize+1);
        for(i64 i = size; i <= newsize; i++) {
            fact[i] = fact[i-1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod/i) %mod;
            ivfact[i] = ivfact[i-1] * inv[i] % mod;
        }
        size = newsize+1;
    }
public:
    combinatoric_s(T mod) : mod(mod), fact(2,1), inv(2,1), ivfact(2,1) {}
    T nCr(i64 N, i64 R) {
        if (R < 0 || N < R || N < 0) return 0;
        update(N);
        return fact[N] * (ivfact[R] * ivfact[N - R] % mod) % mod;
    }
    T nPr(i64 N, i64 R) {
        if (R < 0 || N < R || N < 0) return 0;
        update(N);
        return fact[N] * ivfact[R] % mod;
    }
    T nHm(i64 N, i64 M) {
        return nCr(N+M-1,M);        
    }
};

#endif