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

struct factsearch {
    vector<ll> flags, ret;
    vector<pair<ll,ll>> v;
    factsearch(uint64_t N) {
        if (N < 2) return;
        N++;
        flags.resize(N / 2, 0);
        flags[0] = 1;
        const uint64_t sqrt_x = ceil(sqrt(N) + 0.1) / 2;
        for (uint64_t i = 1; i < sqrt_x; ++i) {
            if (flags[i]) continue;
            const uint64_t p = 2*i + 1;
            flags[i] = p;
            for (uint64_t mult = 2*i*(i+1); mult < N/2; mult += p)
            flags[mult] = p;
        }
        for(uint64_t p = sqrt_x; p < N/2; ++p) {
            if (!flags[p]) flags[p] = 2*p+1;
        }
    }
    vector<ll> retvec() {return flags;}
    uint64_t primQ(uint64_t X) {return flags[X];}
    void flag(ll X) {
        if (X == 1) return;
        if (!(X&1)) {
            ret.push_back(2);
            flag(X/2);
        }
        else {
            ll T = flags[(X-1)/2];
            ret.push_back(T);
            flag(X/T);
        }
        return;
    }
    vector<ll> primfactor(ll x) {
        if (x == 1) {
            ret.resize(1,1);
            return ret;
        }
        ret.resize(0);
        flag(x);
        return ret;
    }
    void countfactor(ll num, ll prev) {
        if (num == 1) return;
        ll T = ((num&1) ? flags[(num-1)/2] : 2);
        if (T == prev) v.back().second++;
        else v.emplace_back(T,1);
        countfactor(num/T,T);
        return;
    }
    ll factcount(ll x) {
        ll cnt = 1;
        v.resize(0);
        countfactor(x,0);
        rep(i,0,v.size()) cnt *= v[i].second+1;
        return cnt;
    }
    void factlist(ll mult, ll depth, ll mx) {
        if (depth == mx) {
            ret.push_back(mult);
            return;
        }
        ll mlt = v[depth].first;
        factlist(mult,depth+1,mx);
        rep(i,0,v[depth].second) {
            factlist(mult *= mlt, depth+1, mx);
        }
        return;
    }
    vector<ll> allfactor(ll x) {
        ret.resize(0);
        v.resize(0);
        countfactor(x,0);
        factlist(1,0,v.size());
        sort(ret.begin(),ret.end());
        return ret;
    }
};

// pow in int, takes mod and returns in O(log(topn))
    ll intpow(ll btmn, ll topn, ll modn) {ll ret_num = 1; btmn%=modn; for(; topn; topn/=2, btmn=(btmn*btmn)%modn) if (topn & 1) ret_num=(ret_num*(btmn%modn))%modn; return ret_num%modn;}


#include <chrono>
using namespace chrono;

int main() {

    ll N; cin >> N;

    auto startInp = high_resolution_clock::now();


    factsearch FR(N);
    vector<ll> v = FR.retvec();
    rep(i,0,v.size()) cout << v[i] << " ";
    cout << endl;

    rep(i,1,N+1) {
        vector<ll> vec = FR.allfactor(i);
        rep(j,0,vec.size()) cout << vec[j] << " ";
        cout << endl; 
        cout << FR.factcount(i) << endl;
    }



    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;


}