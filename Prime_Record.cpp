#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <deque>

using namespace std;

using ll = long long;
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

vector<ll> P;
void primsearchV1(ll N) {
    vector<bool> prim(N+1,true);
    P.push_back(2);
    ll cnt;
    for(ll i=3; i*i<=N; i+=2) {
        if (prim[i]) {
            for (ll j=3*i; j<=N; j+=2*i)
                prim[j] = 0;
            P.push_back(i);
        }
        cnt = i;
    }
    for(ll i=cnt+2; i<=N; i+=2) {
        if (prim[i])
            P.push_back(i);
    }
}


struct primesearch {
    vector<ll> P;
    primesearch(uint64_t N) {
        if (N < 2) return;
        N++;
        vector<bool> flags(N / 2, true);
        flags[0] = false;
        P.push_back(2);
        const uint64_t sqrt_x = ceil(sqrt(N) + 0.1) / 2;
        for (uint64_t i = 1; i < sqrt_x; ++i) {
            if (!flags[i]) continue;
            const uint64_t p = 2*i + 1;
            for (uint64_t mult = 2*i*(i+1); mult < N/2; mult += p)
                flags[mult] = false;
            P.push_back(p);
        }
        for(uint64_t p = sqrt_x; p < N/2; ++p) {
            if (flags[p]) P.push_back(2*p + 1);
        }
    }
    uint64_t primQ(uint64_t X) {return P[X];}
    uint64_t primSize() {return P.size();} 
    vector<ll> retvec() {return P;}
};


#include <chrono>
using namespace chrono;

int main()
{
    ll N; cin >> N; 

    auto startInp = high_resolution_clock::now();
    
    primesearch PR(N);


    cout << PR.primSize() << endl;



    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;

    return 0;
}     