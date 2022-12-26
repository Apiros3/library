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

template <typename T, typename V>
struct RMQ {
    vector<T> dat;
    V N;
    RMQ(V size, vector<T> val) {
        V X = 1;
        while(size > X) 
            X *= 2;
        dat.resize(X*2-1); //default value set to 0
        N = X;
        for(V i = N-1; i < N+size-1; ++i)
            dat[i] = val[i+1-N];
        for(V i = N-2; i >= 0; --i) 
            dat[i] = update_function(dat[i*2+1],dat[i*2+2]);
    }
    void update(V i, T X) {
        i += N-1;
        dat[i] = X;
        while(i) {
            i = (i - 1)/2;
            //updating equation
            dat[i] = update_function(dat[i*2+1],dat[i*2+2]);
        } 
    }
    //some fuction using elements of [a,b)
    T query(V A, V B) { 
        return query_sub(A, B, 0, 0, N);
    }
    T query_sub(V A, V B, V K, V L, V R) {
        //K: current node, dat[K] = dat[L,R)
        if (R <= A or B <= L) {
            //completely out of range
            return val_zero();
        } else if (A <= L and R <= B) {
            //fully in range
            return dat[K];
        } else {
            //partly in range
            T vl = query_sub(A, B, K*2+1, L, (L+R)/2);
            T vr = query_sub(A, B, K*2+2, (L+R)/2, R);
            //updating function for query
            return update_function(vl,vr); 
        }
    }
    T update_function(T vl, T vr) {
        //updating function for any query
        return max(vl,vr);
    }
    T val_zero() {
        return 0;
    }
};


// pow in int, takes mod and returns in O(log(topn))
    ll intpow(ll btmn, ll topn, ll modn) {ll ret_num = 1; btmn%=modn; for(; topn; topn/=2, btmn=(btmn*btmn)%modn) if (topn & 1) ret_num=(ret_num*(btmn%modn))%modn; return ret_num%modn;}


#include <chrono>
using namespace chrono;

int main() {





    auto startInp = high_resolution_clock::now();




    auto stop = high_resolution_clock::now();
    auto durationSys = duration_cast<microseconds> (stop-startInp);
    ld t = durationSys.count();
    cout << t/1000 << " ms" << endl;


}


