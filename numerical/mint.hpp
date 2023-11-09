#ifndef MINT 
#define MINT

#include <istream>
#include <ostream>
#include "modpow_s.hpp"
#include "extgcd.hpp"

//mint (modint)
template<i64 mod> class modint {
    i64 val;
public:
    //constructor via int64_t
    modint(i64 x = 0) : val((x%mod + mod)%mod) {
        if (mod <= 0) {
            throw std::invalid_argument("mod in mint must be positive");
        }
    }
    //copy constructor 
    modint(const modint &r) : val(r.val) {}

    //basic arithmetic
    modint operator +() {
        return modint(val);
    }
    modint operator -() {
        return modint(-val);
    }
    modint operator +(const modint &r) {
        return modint(*this)+=r;
    }
    template <typename T>
    modint operator +(const T &r) {
        return modint(*this)+=r;
    }
    modint operator -(const modint &r) {
        return modint(*this)-=r;
    }
    modint operator *(const modint &r) {
        return modint(*this)*=r;
    }
    modint operator /(const modint &r) {
        return modint(*this)/=r;
    }
    //substitution arithmetic
    modint &operator +=(const modint &r) {
        val += r.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    modint &operator -=(const modint &r) {
        val -= r.val;
        if (val < 0) val += mod;
        return *this;
    }
    modint &operator *=(const modint &r) {
        val = modmul(val, r.val, mod);
        return *this;
    }
    modint &operator /=(const modint &r) {
        i64 x, y;
        i64 d = extGCD(r.val, mod, x, y);
        if (d != 1) {
            throw std::invalid_argument("Zn (modint) cannot divide with numbers with gcd != 1");
        }
        x = (x%mod + mod)%mod;
        val = modpow_s(val, x, mod);
        return *this;
    }
    //for use with integer types
    template <typename T>
    modint &operator +=(const T &r) {
        val += (r%mod + mod)%mod;
        if (val >= mod) val -= mod;
        return *this;
    }
    template <typename T>
    modint &operator -=(const T &r) {
        val -= (r%mod + mod)%mod;
        if (val < 0) val += mod;
        return *this;
    }
    template <typename T>
    modint &operator *=(const T &r) {
        assert(r >= 0);
        val = modmul(val, r, mod);
        return *this;
    }
    template <typename T>
    modint &operator /=(const T &r) {
        i64 x, y;
        i64 d = extGCD(r, mod, x, y);
        if (d != 1) {
            throw std::invalid_argument("Zn (modint) cannot divide with numbers with gcd != 1");
        }
        x = (x%mod + mod)%mod;
        val = modpow_s(val, x, mod);
        return *this;
    }
    //boolean operators
    bool operator ==(const modint &r) {
        return this->val == r.val;
    }
    bool operator !=(const modint &r) {
        return this->val != r.val;
    }

    //special uses
    template <typename T>
    modint pow(modint base, T exponent) {
        return modpow_s(base.val,exponent,mod);
    }

    //input / output
    friend std::istream& operator >>(std::istream &is, modint &x) {
        i64 t; is >> t;
        x = t;
        return (is); 
    }

    friend std::ostream& operator<<(std::ostream &os, const modint &m) {
        return os<<m.val;
    }
};

#endif