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

struct edge{
    int to, cap, rev;
};
vector<vector<edge>> G;
vector<bool> used;
void add_edge(int from, int to , int cap) {
    edge F;
    edge T;
    F.to = to, F.cap = cap, F.rev = G[to].size();
    G[from].push_back(F);
    T.to = from, T.cap = 0, T.rev = G[from].size()-1;
    G[to].push_back(T);
}
int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    rep(i,0,G[v].size()) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f,e.cap));
            if (d > 0) {
                e.cap -=d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    while(1) {
        fill(used.begin(),used.end(),0);
        int f = dfs(s,t,INF);
        if (f==0) return flow;
        flow += f;
    }
}

// pow in int, takes mod and returns in O(log(topn))
    ll intpow(ll btmn, ll topn, ll modn) {ll ret_num = 1; btmn%=modn; for(; topn; topn/=2, btmn=(btmn*btmn)%modn) if (topn & 1) ret_num=(ret_num*(btmn%modn))%modn; return ret_num%modn;}


#include <chrono>
using namespace chrono;

int main() {


    auto startInp = high_resolution_clock::now();

    ll N, M; cin >> N >> M;
    


    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;


}