#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)

ll INF = 1LL << 60;
ld PI = 3.141592653589793;

struct Init {
    Init() {
        cout << setprecision(15);
    }
}init;

ll intpow(ll btmn, ll topn, ll modn) {
    ll ret_num = 1; 
    btmn%=modn; 
    for(; topn; topn/=2, btmn=(btmn*btmn)%modn) 
        if (topn & 1) ret_num=(ret_num*(btmn%modn))%modn; 
    return ret_num%modn;
}

// random generation algorithm
uint64_t xor64() {
    static uint64_t x = 88172645463325252ULL; 
    x = x ^ (x << 13); 
    x = x ^ (x >> 7); 
    return x = x ^ (x << 17);
}

struct Miller {
    ull modpow(ull btmn, ull topn, ull modn) {
        ll ret_num = 1; 
        btmn%=modn; 
        for(; topn; topn/=2, btmn=(btmn*btmn)%modn) 
            if (topn & 1) ret_num=(ret_num*(btmn%modn))%modn; 
        return ret_num%modn;
    }
    ull modmul(ull a, ull b, ull M) {
        ll ret = a * b - M * ull(1.L / M * a * b);
        return ret + M * (ret < 0) - M * (ret >= (ll)M);
    }
    bool isPrime(ull n) {
        if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
        ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n-1), d = n >> s;
        for (ull a : A) {
            ull p = modpow(a%n, d, n), i = s;
            while (p != 1 && p != n - 1 && a % n && i--)
                p = modmul(p,p,n);
            if (p != n-1 && i != s) return 0;
        }
        return 1;
    }
};

#include <chrono>
using namespace chrono;

int main()
{
    ll N; cin >> N; 

    auto startInp = high_resolution_clock::now();

    Miller ML;
    ll cnt = 0;
    rep(i,0,N) if (ML.isPrime(xor64())) cnt++;

    cout << cnt << endl;

    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;

    return 0;
}     