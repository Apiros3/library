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


ll smallnCr(ll N, ll R) {
    if (2*R > N) R = N-R;
    ll ret = 1;
    rep(i,1,R+1) {
        ret *= N+1-i;
        ret /= i;
    }
    return ret;
}


#include <chrono>
using namespace chrono;

int main() {

    ll N, R; cin >> N >> R;

    auto startInp = high_resolution_clock::now();

    cout << smallnCr(N,R) << endl;
    

    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;


}