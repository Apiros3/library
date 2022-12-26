#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <deque>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)

ll INF = 1LL << 60;
ld PI = 3.141592653589793;

struct Init {
    Init() {
        cout << setprecision(15);
    }
}init;

ull intpow(ll btmn, ll topn, ll modn) {
    ll ret_num = 1; 
    btmn%=modn; 
    for(; topn; topn/=2, btmn=(btmn*btmn)%modn) 
        if (topn & 1) ret_num=(ret_num*(btmn%modn))%modn; 
    return ret_num%modn;
}

//for prime mods and N < 10^7 (≈1000 ms)
struct BinomCoef {
    vector<ll> fct, iv, ivfct;
    ll md;
    BinomCoef(ll N, ll mod) {
        fct.resize(N+1,1);
        iv.resize(N+1,1);
        ivfct.resize(N+1,1);
        md = mod;
        rep(i,2,N+1) {
            fct[i] = fct[i-1] * i % mod;
            iv[i] = mod - iv[mod%i] * (mod/i)%mod;
            ivfct[i] = ivfct[i-1] * iv[i] % mod;
        }
    }
    ull nCr(ull N, ull R) {
        return fct[N] * (ivfct[R] * ivfct[N - R] % md) % md;
    }
    ull nPr(ull N, ull R) {
        return fct[N] * ivfct[R] % md;
    }
};


#include <chrono>
using namespace chrono;

int main()
{
    ll T, m; cin >> T >> m;
    freopen("output.txt","w",stdout);

    auto startInp = high_resolution_clock::now();
;
    BinomCoef BC(m,m);
    rep(i,0,T) {
        ll N, K; cin >> N >> K;
        cout << BC.nCr(N%m,K%m) << endl;
    }

    
    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    cout << durationSys.count() << " ms" << endl;

    return 0;
}     
