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

ll intpow(ll btmn, ll topn, ll modn) {ll ret_num = 1; btmn%=modn; for(; topn; topn/=2, btmn=(btmn*btmn)%modn) if (topn & 1) ret_num=(ret_num*(btmn%modn))%modn; return ret_num%modn;}

struct factor18 {
    vector<uint64_t> P;
    ll cnt = 1;
    factor18(uint64_t N) {
        if (N < 2) return;
        N++;
        vector<bool> flags(N / 2, 1);
        flags[0] = 0;
        P.push_back(2);
        P.resize(50847534);
        const uint64_t sqrt_x = ceil(sqrt(N) + 0.1) / 2;
        for (uint64_t i = 1; i < sqrt_x; ++i) {
            if (!flags[i]) continue;
            const uint64_t p = 2*i + 1;
            for (uint64_t mult = 2*i*(i+1); mult < N/2; mult += p)
                flags[mult] = 0;
            P[cnt++]=p;
        }
        for(uint64_t p = sqrt_x; p < N/2; ++p) {
            if (flags[p]) P[cnt++] = (2*p + 1);
        }
        P.resize(cnt);
    }
    vector<ll> ret;
    void DFS(ll prod, ll depth, vector<pair<ll,ll>> v) {
        if (depth == v.size()-1) {
            rep(i,0,v[depth].second+1)
                ret.push_back(prod*intpow(v[depth].first,i,INF));
            return;
        }
        rep(i,0,v[depth].second+1) 
            DFS(prod*intpow(v[depth].first,i,INF),depth+1,v);
    }
    vector<ll> fct(ll N) {
        vector<pair<ll,ll>> fct;
        ll fctsiz = 0, cnt = 0;
        while(P[cnt]*P[cnt]<=N) {
            if (N%P[cnt]==0) {
                if (fctsiz==0) 
                    fct.emplace_back(P[cnt],1);
                else if (P[cnt]==fct[--fctsiz].first)
                    fct[fctsiz].second++;
                else 
                    fct.emplace_back(P[cnt],1);
                fctsiz++;
                N/=P[cnt];
            }
            else cnt++;
        }
        if (fctsiz==0) fct.emplace_back(N,1);
        else if (N==fct[fctsiz-1].first) fct[fctsiz-1].second++;
        else fct.emplace_back(N,1);
        ret.resize(0);
        DFS(1,0,fct);
        sort(ret.begin(),ret.end());
        return ret; 
    }
    uint64_t primQ(uint64_t X) {return P[X];}
    uint64_t primSize() {return cnt;} 
};

#include <chrono>
using namespace chrono;

int main()
{
    // auto startInp = high_resolution_clock::now();
    
    ll N = intpow(10,9,INF);
    factor18 PR(N);

    ll Q; cin >> Q;
    rep(i,0,Q) {
        ll K; cin >> K;
        vector<ll> v = PR.fct(K);
        cout << v.size() << " ";
        rep(i,0,v.size()) cout << v[i] << " ";
        cout << endl;
    }
    

    // auto stop = high_resolution_clock::now();
    // auto durationSys = duration_cast<microseconds> (stop-startInp);
    // ld t = durationSys.count();
    // cout << t/1000 << " ms" << endl;

    return 0;
}     