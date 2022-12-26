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

struct treepath {
    vector<ll> ret, prev;
    ll furthestpoint, mxdist;
    treepath(ll N, vector<vector<pair<ll,ll>>> V) {
        ll T = V.size();
        ret.resize(T,-1), prev.resize(T);
        queue<ll> que;
        que.push(N);
        prev[N] = N;
        ret[N] = 0;
        mxdist = 0;
        furthestpoint = N;
        while(!que.empty()) {
            ll cnt = que.front(); 
            que.pop();
            rep(i,0,V[cnt].size()) {
                ll tmp = V[cnt][i].first;
                if (ret[tmp] != -1) continue;
                ret[tmp] = ret[cnt] + V[cnt][i].second;
                if (ret[tmp] > mxdist) {
                    mxdist = ret[tmp];
                    furthestpoint = tmp;
                }
                prev[tmp] = cnt;
                que.push(tmp);
            }
        }
    }
    vector<ll> retvec() {return ret;}
    vector<ll> retprev() {return prev;}
    vector<ll> diameterpath() {
        ll pos = furthestpoint;
        vector<ll> pth(1,pos);
        while(pos != prev[pos]) {
            pth.push_back(prev[pos]);
            pos = prev[pos];
        }
        return pth;
    }
    ll fpoint() {return furthestpoint;}
};


#include <chrono>
using namespace chrono;

int main() {

    ll N; cin >> N;

    // auto startInp = high_resolution_clock::now();

    vector<vector<pair<ll,ll>>> V(N);
    rep(i,0,N-1) {
        ll A, B, C; cin >> A >> B >> C; 
        V[A].emplace_back(B,C);
        V[B].emplace_back(A,C);
    }
    treepath TR(0, V);
    treepath FR(TR.fpoint(),V);

    vector<ll> vec = FR.retvec();

    vector<ll> v = FR.diameterpath();
    cout << vec[v.front()] << " " << v.size() << endl;
    rep(i,0,v.size()) cout << v[i] << " ";
    cout << endl;


    // auto stop = high_resolution_clock::now();
    // auto durationSys = duration_cast<microseconds> (stop-startInp);
    // ld t = durationSys.count();
    // // cout << t/1000 << " ms" << endl;


}