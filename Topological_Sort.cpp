#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<ll>>;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)


ll INF = 1LL << 60;
ld PI = 3.141592653589793;

struct Init {
    Init() {
        cout << setprecision(15);
    }
}init;

struct Topological_Sort {
    vector<ll> ret;
    Topological_Sort(Graph G, vector<ll> deg) {
        queue<ll> que;
        rep(i,0,G.size()) if (deg[i] == 0) que.push(i);
        
        while(!que.empty()) {
            ll v = que.front();
            que.pop();
            ret.push_back(v);

            for (auto nv: G[v]) {
                --deg[nv];
                if (deg[nv] == 0) que.push(nv);
            }
        }
        reverse(ret.begin(),ret.end());
    }
    vector<ll> vec() {return ret;}
};

#include <chrono>
using namespace chrono;

int main()
{
    ll N, M; cin >> N >> M; 

    auto startInp = high_resolution_clock::now();

    Graph G(N);
    vector<ll> deg(N,0);
    rep(i,0,M) {
        ll A, B; 
        cin >> A >> B; 
        G[B].push_back(A);
        deg[A]++;
    }
    Topological_Sort TP(G, deg);
    vector<ll> V = TP.vec();
    rep(i,0,V.size()) cout << V[i] << endl;

    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;

    return 0;
}     