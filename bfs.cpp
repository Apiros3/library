#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define rep(i,start,end) for(ll i=start; i<end; i++)
#define rrep(i,start,end) for(ll i=start; i>=end; i--)
#define all(a) a.begin(),a.end() 

ll INF = 1LL << 60;
ld PI = 3.141592653589793;

struct Init {
    Init() {
        cout << setprecision(15);
    }
}init;


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

int main()
{
    

    
    return 0;
}    