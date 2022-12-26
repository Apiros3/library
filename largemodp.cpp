#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)

ull INF = 1LL << 60;
ld PI = 3.141592653589793;

struct Init {
    Init() {
        cout << setprecision(15);
    }
}init;


ll largemodp(string num, ll mod) {
    ll ret = 0LL;
    ll check = (1LL<<62)/5 - 9;
    
    rep(i,0,num.length()) {
        ret += (num[i] - '0');
        ret *= 10;
        if (ret > check) ret%=mod;
    }
    return ret%mod;
}

ll slow_largemodp(string num, ll mod) {
    ll ret = 0;
    rep(i,0,num.length()) {
        ret += (num[i] - '0');
        ret = (ret*10)%mod;
    }
    return ret;
}


// pow in int, takes mod and returns in O(log(topn))
    ll intpow(ll btmn, ll topn, ll modn) {ll ret_num = 1; btmn%=modn; for(; topn; topn/=2, btmn=(btmn*btmn)%modn) if (topn & 1) ret_num=(ret_num*(btmn%modn))%modn; return ret_num%modn;}


#include <chrono>
using namespace chrono;

int main() {


    string N;
    ll mod;
    cin >> N >> mod;

    auto startInp = high_resolution_clock::now();

    cout << largemodp(N,mod) << endl;
    // cout << slow_largemodp(N,mod) << endl;


    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;


}