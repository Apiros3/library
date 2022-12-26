#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vv = vector<vector<ll>>;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)


ll INF = 1LL << 60;
ld PI = 3.141592653589793;

struct Init {
    Init() {
        cout << setprecision(15);
    }
}init;

vector<ll> BFS_map(uint64_t H,uint64_t W,uint64_t pos) {
    vector<ll> ret;
    queue<ll> que;
    que.push(pos);
    ret[pos] = 0;
    ll X[] = {-1,0,1,0}, Y[] = {0,1,0,-1};
    while(!que.empty()) {
        ll tmp = que.front();
        que.pop();
        ll tx = tmp/W, ty = tmp%W;



    }

    return ret;
}

vector<ll> BFS_Graph(vv G, int64_t size, int64_t pos) {
    vector<ll> ret(size,-1);
    queue<int64_t> Q;
    ret[pos] = 0;
    Q.push(pos);

    while(!Q.empty()) {
        int64_t v = Q.front();
        Q.pop();

        for (int64_t nv : G[v]) {
            if (ret[nv] != -1) continue;
            ret[nv] = ret[v] + 1;
            Q.push(nv);
        }
    }
    return ret;
}


template <typename T, typename V>
struct bfs_bip {
    vector<T> dist, color;
    V color0 = 0, color1 = 0;
    bool bipartite_t = true;
    bfs_bip(vector<vector<V>> pos, V size, V start) {
        queue<V> que;
        dist.resize(size+(start != 0),INF);
        color.resize(size+(start != 0));
        que.push(start);
        dist[start] = 0;
        color[start] = 1;
        while(!que.empty()) {
            V v = que.front();
            auto elem = pos[v];
            que.pop();
            for(V nv : elem) {
                if (dist[nv] < dist[v] + 1) {
                    dist[nv] = dist[v] + 1;
                    color[nv] = 1 - color[v];
                    que.push(nv);
                }
                else if (dist[nv] == dist[v]) {
                    bipartite_t = false;
                }
            }            
        }
        for(V v : color) {
            if (v) color1++;
        }
        color0 = size - color1;
    }
    bool bip() {return bipartite_t;} 
    vector<T> ret() {return dist;}
    pair<V,V> col() {return {color1,color0};}
};

template <typename T, typename V>
struct bfs_d {
    vector<T> dist;
    bfs_d(vector<vector<pair<V,T>>> pos, V size, V start) {
        queue<V> que;
        dist.resize(size+1,INF);  
        que.push(start);
        dist[start] = 0;
        while(!que.empty()) {
            V v = que.front();
            auto elem = pos[v];
            que.pop();
            for(pair<V,T> (nv,d) : elem) {
                if (dist[nv] < dist[v] + d) {
                    dist[nv] = dist[v] + d;
                    que.push(nv);
                }
            }            
        }
    } 
    vector<T> ret() {return dist;}
};


struct bellmanford {
        

};

#include <chrono>
using namespace chrono;

int main()
{
    ll N, M; cin >> N >> M; 

    auto startInp = high_resolution_clock::now();

    vv vec(N);
    rep(i,0,M) {
        ll A, B; cin >> A >> B; 
        vec[A].push_back(B);
        // V[B].push_back(A);
    }

    vector<ll> T;
    T = BFS_Graph(vec, 0, N);
    rep(i,0,N) cout << T[i] << endl;


    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;

    return 0;
}     