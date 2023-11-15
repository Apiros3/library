#line 2 "test.cpp"
// #include <bits/stdc++.h>
#line 1 "apiros3_lib.hpp"



//from BIT
#line 1 "bit/ctz.hpp"



#line 1 "general/fixed_integer.hpp"



#include <stdint.h>
typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;


#line 5 "bit/ctz.hpp"

/**
 * reference https://github.com/shino16/cpp-library/blob/main/bit/ctz.hpp 
 * 
 */

template <typename T>
i32 ctz(T num) {
    if (!num) {
        return sizeof(T) * 8;
    }
    if constexpr (sizeof(T) <= sizeof(unsigned)) {
        return __builtin_ctz((unsigned)num);
    } 
    else if constexpr (sizeof(T) <= sizeof(unsigned long long)) {
        return __builtin_ctz((unsigned long long)num);
    }
    else if constexpr (sizeof(T) <= sizeof(unsigned long long) * 2) {
        unsigned long long y = num;
        return y ? ctz(y)
            : sizeof(y) * 8 + ctz((unsigned long long)(num >> sizeof(y) * 8));
    }
}


#line 6 "apiros3_lib.hpp"

//from GENERAL
#line 1 "general/debug.hpp"



#include <iostream>
#include <typeinfo> 
#include <vector>
#include <map>
#include <set>

template <typename T>
void debug_ws(T val) {
    try {
        std::cout << val;
    }
    catch (const std::exception &e) {
        std::cout << "type error: debug cannot be used on " << typeid(T).name() << std::endl; 
    }
}
template <typename T>
void debug(T val) {
    debug_ws(val);
    std::cout << " ";
}

template <typename T>
void debug_ws(std::vector<T> &G) {
    for(T &u : G) {
        debug(u);
    }
}
template <typename T>
void debug(std::vector<T> &G) {
    debug_ws(G);
    std::cout << std::endl;
}

template <typename T, typename W>
void debug(std::pair<T,W> &u) {
    debug_ws(u);
    std::cout << " ";
}
template <typename T, typename W>
void debug_ws(std::pair<T,W> &u) {
    std::cout << "{";
    debug_ws(u.first);
    std::cout << ", ";
    debug_ws(u.second);
    std::cout << "}";
}

template <typename T, typename W>
void debug(std::map<T, W> &mp) {
    debug_ws(mp);
    std::cout << std::endl;
}
template <typename T, typename W>
void debug_ws(std::map<T, W> &mp) {
    for(std::pair<T,W> &u : mp) {
        debug(u);
    }
}

template <typename T> 
void debug_ws(std::set<T> &st) {
    for(T &u : st) {
        debug(u);
    }
}
template <typename T> 
void debug(std::set<T> &st) {
    debug_ws(st);
    std::cout << std::endl;
}

template <typename T> 
void debug_ws(std::multiset<T> &st) {
    for(T &u : st) {
        debug(u);
    }
}
template <typename T> 
void debug(std::multiset<T> &st) {
    debug_ws(st);
    std::cout << std::endl;
}

;

#line 10 "apiros3_lib.hpp"

//from STD_EXTENSION
#line 1 "std_extension/set.hpp"



#line 5 "std_extension/set.hpp"

template <typename T>
std::set<T> operator |(const std::set<T> &a, const std::set<T> &b) {
    if (a.size() > b.size()) {
        return a|=b;
    }
    else {
        return b|=a;
    }
}
template <typename T>
std::set<T> operator &(const std::set<T> &a, const std::set<T> &b) {
    if (a.size() > b.size()) {
        return a&=b;
    }
    else {
        return b&=a;
    }
}
template <typename T>
std::set<T> operator -(const std::set<T> &a, const std::set<T> &b) {
    return a-=b;
}

template <typename T>
std::set<T> &operator |=(std::set<T> &a, const std::set<T> &b) {
    for(T &u : b) {
        a.insert(u);
    }
}
template <typename T>
std::set<T> &operator &=(std::set<T> &a, const std::set<T> &b) {
    std::set<T> st;
    for(T u : b) {
        if (a.count(u)) {
            st.insert(u);
        }
    }
    return a = st;
}
template <typename T>
std::set<T> &operator -=(std::set<T> &a, const std::set<T> &b) {
    std::set<T> st;
    for(T u : b) {
        if (!a.count(u)) {
            st.insert(u);
        }
    }
    return a = st;
}

// template <typename T>
// std::set<std::set<T>> powerset(std::set<T> st) {

    
// }


#line 1 "std_extension/vector.hpp"



#line 6 "std_extension/vector.hpp"


template<typename T>
std::vector<T>& operator +=(std::vector<T> &lhs, const std::vector<T> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::length_error("vectors must be same size to add");
    }
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] += rhs[i];
    }
    return lhs;
}
template<typename T>
std::vector<T> operator +(std::vector<T> lhs, const std::vector<T> &rhs) {
    return lhs += rhs;
}
template<typename T>
std::vector<T>& operator -=(std::vector<T> &lhs, const std::vector<T> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::length_error("vectors must be same size to subtract");
    }
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] -= rhs[i];
    }
    return lhs;
}
template<typename T>
std::vector<T> operator -(std::vector<T> lhs, const std::vector<T> &rhs) {
    return lhs -= rhs;
}
template<typename T>
std::vector<T>& operator *=(std::vector<T> &lhs, const std::vector<T> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::length_error("vectors must be same size to multiply");
    }
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] *= rhs[i];
    }
    return lhs;
}
template<typename T>
std::vector<T> operator *(std::vector<T> lhs, const std::vector<T> &rhs) {
    return lhs *= rhs;
}
template<typename T>
std::vector<T>& operator /=(std::vector<T> &lhs, const std::vector<T> &rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::length_error("vectors must be same size to divide");
    }
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] /= rhs[i];
    }
    return lhs;
}
template<typename T>
std::vector<T> operator /(std::vector<T> lhs, const std::vector<T> &rhs) {
    return lhs /= rhs;
}

template<typename T>
std::vector<T>& operator +=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] += rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator +(std::vector<T> lhs, const T& rhs) {
    return lhs += rhs;
}
template<typename T>
std::vector<T>& operator -=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] -= rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator -(std::vector<T> lhs, const T& rhs) {
    return lhs -= rhs;
}
template<typename T>
std::vector<T>& operator *=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] *= rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator *(std::vector<T> lhs, const T& rhs) {
    return lhs *= rhs;
}
template<typename T>
std::vector<T>& operator /=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] /= rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator /(std::vector<T> lhs, const T& rhs) {
    return lhs /= rhs;
}
template<typename T>
std::vector<T>& operator %=(std::vector<T> &lhs, const T& rhs) {
    for(int i = 0; i < lhs.size(); ++i) {
        lhs[i] %= rhs;
    }
    return lhs;
}
template<typename T>
std::vector<T> operator %(std::vector<T> lhs, const T& rhs) {
    return lhs %= rhs;
}



#line 14 "apiros3_lib.hpp"

//from STRUCTURE
#line 1 "structure/binary_trie.hpp"



#line 6 "structure/binary_trie.hpp"





#line 1 "structure/char_trie.hpp"



#line 7 "structure/char_trie.hpp"

template<typename T = i64>
class Char_Trie {
public:
    class Trie {
    public:
        std::map<char,Trie> child;
        T count;
        i64 depth;
        Trie(i64 depth = 0) : depth(depth) {}
    };

    Trie *root = new Trie;
private:
    T zero, one;

    Trie find(std::string& S) {
        Trie *cur = root;
        for(auto &u : S) {
            if (cur->child.count(u)) {
                cur = cur->child[u];
            }
            else {
                return NULL;
            }
        }        
        return cur;
    }
    Trie find_s(std::string& S) {
        Trie *cur = root;
        for(auto &u : S) {
            if (!cur->child.count(u)) {
                cur->child[u] = new Trie(cur->depth + 1);
            }
            cur = cur->child[u];
        }
        return cur;
    }

    T dfs_T(Trie cur, T(*func)(), T(*eval)()) {
        T ret = func(cur);
        for(auto u : (cur->child)) {
            ret = eval(ret,dfs(u.second,func));
        }
        return ret;
    }
    void dfs_T(Trie cur, T(*func)(), bool(*cond)(),  std::vector<T> &vec) {
        vec.emplace_back(func(cur));
        if (cond(cur)) {
            for(auto u : (cur->child)) {
                dfs(u.second, func, vec);
            }
        }
        return;
    }

    i64 dfs_i64(Trie cur, i64(*func)(), i64(*eval)) {
        i64 ret = func(cur);
        for(auto u : (cur->child)) {
            ret = eval(ret,dfs(u.second,func));
        }
        return ret;
    }
    void dfs_i64(Trie cur, i64(*func)(), bool(*cond)(),  std::vector<i64> &vec) {
        vec.emplace_back(func(cur));
        if (cond(cur)) {
            for(auto u : (cur->child)) {
                dfs(u.second, func, vec);
            }
        }
        return;
    }

public:
    Char_Trie(T zero, T one) : zero(zero), one(one) {}

    T count(std::string& S) {
        Trie *loc = find(S);
        if (loc == NULL) return zero;
        return loc->count;
    }
    i64 child_count(std::string& S) {
        Trie *loc = find(S);
        return loc->child.size();
    }
    void insert(std::string &S, T counter) {
        Trie *loc = find_s(S);
        loc->count += counter;
    }
    void erase(std::string S, T counter) {
        char tmp = S.back();
        S.pop_back();
        Trie *loc = find(S);
        if (loc->child.count(tmp) != NULL) {
            loc->child[tmp].count -= counter;
            if (loc->child[tmp].count <= zero) {
                loc->child.erase(tmp);
            }
        }
    }
    void insert(std::string &S) {
        insert(S, one);
    }
    void erase(std::string &S) {
        erase(S,one);
    }
    T total_count() {
        return dfs_T(root, [&](Trie cur){
            return cur.count();
        }, [&](T a, T b){
            return a + b;
        });
    }
    T max_count() {
        return dfs_T(root, [&](Trie cur) {
            return cur.count();
        }, [&](T a, T b) {
            return std::max(a,b);
        });
    }
    T min_count() {
        return dfs_T(root, [&](Trie cur) {
            return cur.count();
        }, [&](T a, T b) {
            if (a == 0) return b;
            else if (b == 0) return a;
            else return std::min(a,b);
        });
    }
    std::vector<T> DFS_T(T(*func)(), bool(*condition)()) {
        std::vector<T> ret;
        if (condition(root)) {
            dfs_T(root, func, condition, ret);
        }
        return ret;
    }
    std::vector<i64> DFS_i64(i64(*func)(), bool(*condition)()) {
        std::vector<i64> ret;
        if (condition(root)) {
            dfs_i64(root, func, condition, ret);
        }
        return ret;
    }

};



#line 1 "structure/depque.hpp"



#line 6 "structure/depque.hpp"

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class depriority_queue {
private:


public:
  

  
};


#line 1 "structure/range_sum.hpp"



#line 6 "structure/range_sum.hpp"

template<
    class T = i64
> struct range_sum {
private:
    std::vector<T> csum;

public:
    range_sum(std::vector<T> vec) {
        i32 N = vec.size();
        csum.resize(N+1);
        for(i32 i = 0; i < N; i++) {
            csum[i+1] = csum[i] + vec[i];
        }
    }
    //sum vec[L..R)
    T range(i32 L, i32 R) {
        return csum[R] - csum[L]; 
    }
    //sum vec[0..N]
    T range(i32 N) {
        return csum[N+1];
    }
};

template <typename T>
void debug(range_sum<T> RS) {
    for(auto u : RS.csum) {
        debug(u);
    }
    std::cout << '\n';
}


#line 20 "apiros3_lib.hpp"
// #include "structure/segtree.hpp"
#line 1 "structure/unionfind.hpp"



#line 6 "structure/unionfind.hpp"

struct UnionFind {
private:
    std::vector<i32> par;
    std::vector<std::vector<i32>> group_elems;
public:
    std::vector<i32> group_size;
    UnionFind(i32 N) : par(N), group_elems(N), group_size(N,1) {
        for(i32 i = 0; i < N; i++) {
            par[i] = i;
            group_elems[i].push_back(i);
        }
    }
    i32 find(i32 N) {
        if (par[N] == N) {
            return N;
        }
        return (par[N] = find(par[N]));
    } 
    bool connected(i32 A, i32 B) {
        return (find(A) == find(B));
    }
    void merge(i32 A, i32 B) {
        A = find(A); B = find(B);
        if (A != B) {
            if (group_size[A] < group_size[B]) {
                std::swap(A,B);
            }
            par[B] = A;
            i32 temp = group_size[A];
            group_size[A] += group_size[B];
            group_elems[A].resize(group_size[A]);
            for(i32 i = 0; i < group_size[B]; i++) {
                group_elems[A][temp+i] = group_elems[B][i];
            }
        }
    }
    std::vector<i32> group(i32 N) {
        return group_elems[N];
    }
};


#line 22 "apiros3_lib.hpp"

//from GRAPH
#line 1 "graph/bfs.hpp"



#line 6 "graph/bfs.hpp"
#include <queue>

struct BFS_UW {
private:
    i64 INF = 1ll << 60;
public:
    std::vector<i64> dist, prev;
    BFS_UW(std::vector<std::vector<i64>> adj, i64 start = 0) : dist(adj.size(),INF) {
        dist[0] = 0;
        std::queue<i64> que;
        que.push(0);
        while(!que.empty()) {
            i64 top = que.front(); que.pop();
            for(auto u : adj[top]) {
                if (dist[u] > dist[top] + 1) {
                    dist[u] = dist[top] + 1;
                    prev[u] = top;
                    que.push(u);
                } 
            }
        }
    }
    i64 query(i64 Q) {
        return dist[Q];
    }
};


#line 1 "graph/MST.hpp"



#line 7 "graph/MST.hpp"
#include <tuple>

template<
    class T = i64,
    class Container = std::vector<std::pair<T,i64>>,
    class Compare = std::less<typename Container::value_type>
> class mst {
private:
    T sum = 0;
    std::vector<i64> used;
    // std::vector<std::pair<T,T>> edge_list;
public:
    mst(std::vector<std::vector<std::pair<i64,T>>> adj) : used(adj.size()) /**, edge_list(adj.size())*/ {
        i64 N = adj.size();
        used[0] = 1;
        std::priority_queue<std::pair<T,i64>,Container,Compare> que;
        for(auto u : adj[0]) {
            que.emplace(u.second,u.first);
        }
        while(!que.empty()) {
            auto tmp = que.top(); que.pop();
            if (used[tmp.second]) continue;
            sum += tmp.first;
            i64 cur = tmp.second;
            used[cur] = 1;
            for(auto u : adj[cur]) {
                que.emplace(u.second,u.first);
            }
        }
    }
    T weight() {
        return sum;
    }
};


#line 26 "apiros3_lib.hpp"

//from MATRIX
#line 1 "matrix/matrix.hpp"



#line 5 "matrix/matrix.hpp"
#include <cassert>
#include <algorithm>
#include <ostream>
#line 10 "matrix/matrix.hpp"

template <typename T> 
class Matrix {
private:
    using MAT = std::vector<std::vector<T>>;
    MAT resize(MAT A, i32 sizeH, i32 sizeW) {
        for(auto &u : A) u.resize(sizeW);
        A.resize(sizeH,std::vector<T>(sizeW));
        return A;
    }
    std::tuple<MAT,MAT,MAT,MAT> divide(MAT A) {
        i32 N = A.size();
        MAT A11(N/2,std::vector<T>(N/2)), A12 = A11, A21 = A11, A22 = A11;
        for(i32 i = 0; i < N; i++) {
            for(i32 j = 0; j < N; j++) {
                if (i < N/2 && j < N/2) {
                    A11[i][j] = A[i][j];
                }
                else if (i < N/2) {
                    A12[i][j - N/2] = A[i][j];
                }
                else if (j < N/2) {
                    A21[i - N/2][j] = A[i][j];
                }
                else {
                    A22[i - N/2][j - N/2] = A[i][j];
                }
            }
        }
        return make_tuple(A11,A12,A21,A22);
    } 
    MAT join(MAT A11, MAT A12, MAT A21, MAT A22) {
        i32 N = A11.size() * 2;
        MAT ret(N, std::vector<T>(N));
        for(i32 i = 0; i < N; i++) {
            for(i32 j = 0; j < N; j++) {
                if (i < N/2 && j < N/2) {
                    ret[i][j] = A11[i][j];
                }
                else if (i < N/2) {
                    ret[i][j] = A12[i][j - N/2];
                }
                else if (j < N/2) {
                    ret[i][j] = A21[i - N/2][j];
                }
                else {
                    ret[i][j] = A22[i - N/2][j - N/2];
                }
            }
        }
        return ret;
    }
    MAT prod(MAT A, MAT B) {
        if (A.size() == 1) {
            return MAT{{A[0][0]*B[0][0]}};
        }
        auto [A11, A12, A21, A22] = divide(A);
        auto [B11, B12, B21, B22] = divide(B);

        MAT M1 = prod(A11 + A22, B11 + B22);
        MAT M2 = prod(A21 + A22, B11);
        MAT M3 = prod(A11, B12 - B22);
        MAT M4 = prod(A22, B21 - B11);
        MAT M5 = prod(A11 + A12, B22);
        MAT M6 = prod(A21 - A11, B11 + B12);
        MAT M7 = prod(A12 - A22, B21 + B22);

        return join(M1 + M4 - M5 + M7, M3 + M5, M2 + M4, M1 - M2 + M3 + M6);
    }
public:
    i32 H, W;
    MAT mat;
    Matrix(MAT vec) : mat(vec) {
        H = vec.size();
        assert(H != 0);
        W = vec[0].size();
        for(std::vector<T> &u : vec) {
            assert(u.size() == W);
        }
    }
    //copy constructor
    Matrix(const Matrix &r) : mat(r.mat), H(r.H), W(r.W) {}

    Matrix operator +() {
        return Matrix(mat);
    }
    Matrix operator -() {
        MAT tmat = mat;
        for(std::vector<T> &u : tmat) {
            for(T &v: u) {
                v = -v;
            }
        }
        return Matrix(tmat);
    }
    Matrix operator +(const Matrix &r) {
        return Matrix(*this)+=r;
    }
    Matrix operator -(const Matrix &r) {
        return Matrix(*this)-=r;
    }
    Matrix operator *(const Matrix &r) {
        return Matrix(*this)*=r;
    }
    Matrix &operator +=(const Matrix &r) {
        assert(H == r.H && W == r.W);
        for(i32 i = 0; i < H; i++) {
            for(i32 j = 0; j < W; j++) {
                mat[i][j] += r.mat[i][j];
            }
        }
        return *this;
    }
    Matrix &operator -=(const Matrix &r) {
        assert(H == r.H && W == r.W);
        for(i32 i = 0; i < H; i++) {
            for(i32 j = 0; j < W; j++) {
                mat[i][j] -= r.mat[i][j];
            }
        }
        return *this;
    }
    Matrix &operator *=(const Matrix &r) {
        assert(W == r.H);
        //TODO min 2beki number de kousokuka dekiru
        i32 mx = std::max(H, std::max(W, r.W)), size = 1;
        while(size < mx) size *= 2;
        W = r.W;
        mat = resize(prod(resize(mat, size, size), resize(r.mat,size,size)), H, W);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os, const Matrix &m) {
        for(auto u : m.mat) {
            for(auto v : u) {
                os << v << " ";
            }
            os << std::endl;
        }
        return os;
    }

};



#line 29 "apiros3_lib.hpp"

//from NUMERICAL
#line 1 "numerical/combinatoric.hpp"



#line 1 "numerical/mint.hpp"



#include <istream>
#line 1 "numerical/modpow_s.hpp"



#line 1 "numerical/modmul.hpp"



#line 6 "numerical/modmul.hpp"

typedef long double ld;

/**
 * reference: https://github.com/kth-competitive-programming/kactl/blob/main/doc/modmul-proof.md
*/

//returns a*b mod M (for M in uint64_t)
u64 modmul(u64 a, u64 b, u64 mod) {
    i64 ret = a * b - mod * (u64)(ld(a) * ld(b) / ld(mod));
    return ret + mod * (ret < 0) - mod * (ret >= (i64)mod);
}


#line 7 "numerical/modpow_s.hpp"


u64 modpow_s(u64 base, u64 exponent, u64 mod) {
    assert(mod > 0);
    u64 ret = 1;
    base %= mod;
    while(exponent) {
        if (exponent&1) {
            ret = modmul(ret, base, mod);
        }
        exponent /= 2;
        base = modmul(base,base,mod);
    }
    return ret;
}


#line 1 "numerical/extgcd.hpp"



#line 6 "numerical/extgcd.hpp"

// returns gcd of a and b
// stores (x,y) s.t. ax + by = gcd(a,b)
i64 extGCD(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    /**
     * d = by + (a%b)x
     * division algo: a - (a/b)b = a%b
     * d = by + ax - (a/b)bx 
     * d = ax + b(y - (a/b)x)
     */
    i64 d = extGCD(b, a%b, y, x);
    y -= (a/b)*x;
    return d;
}


#line 8 "numerical/mint.hpp"

//mint (modint)
template<i64 mod> class modint {
    i64 val;
public:
    //constructor via int64_t
    modint(i64 x = 0) : val((x%mod + mod)%mod) {
        if (mod <= 0) {
            throw std::invalid_argument("mod in mint must be positive");
        }
    }
    //copy constructor 
    modint(const modint &r) : val(r.val) {}

    //basic arithmetic
    modint operator +() {
        return modint(val);
    }
    modint operator -() {
        return modint(-val);
    }
    modint operator +(const modint &r) {
        return modint(*this)+=r;
    }
    template <typename T>
    modint operator +(const T &r) {
        return modint(*this)+=r;
    }
    modint operator -(const modint &r) {
        return modint(*this)-=r;
    }
    modint operator *(const modint &r) {
        return modint(*this)*=r;
    }
    modint operator /(const modint &r) {
        return modint(*this)/=r;
    }
    //substitution arithmetic
    modint &operator +=(const modint &r) {
        val += r.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    modint &operator -=(const modint &r) {
        val -= r.val;
        if (val < 0) val += mod;
        return *this;
    }
    modint &operator *=(const modint &r) {
        val = modmul(val, r.val, mod);
        return *this;
    }
    modint &operator /=(const modint &r) {
        i64 x, y;
        i64 d = extGCD(r.val, mod, x, y);
        if (d != 1) {
            throw std::invalid_argument("Zn (modint) cannot divide with numbers with gcd != 1");
        }
        x = (x%mod + mod)%mod;
        val = modpow_s(val, x, mod);
        return *this;
    }
    //for use with integer types
    template <typename T>
    modint &operator +=(const T &r) {
        val += (r%mod + mod)%mod;
        if (val >= mod) val -= mod;
        return *this;
    }
    template <typename T>
    modint &operator -=(const T &r) {
        val -= (r%mod + mod)%mod;
        if (val < 0) val += mod;
        return *this;
    }
    template <typename T>
    modint &operator *=(const T &r) {
        assert(r >= 0);
        val = modmul(val, r, mod);
        return *this;
    }
    template <typename T>
    modint &operator /=(const T &r) {
        i64 x, y;
        i64 d = extGCD(r, mod, x, y);
        if (d != 1) {
            throw std::invalid_argument("Zn (modint) cannot divide with numbers with gcd != 1");
        }
        x = (x%mod + mod)%mod;
        val = modpow_s(val, x, mod);
        return *this;
    }
    //boolean operators
    bool operator ==(const modint &r) {
        return this->val == r.val;
    }
    bool operator !=(const modint &r) {
        return this->val != r.val;
    }

    //special uses
    template <typename T>
    modint pow(modint base, T exponent) {
        return modpow_s(base.val,exponent,mod);
    }

    //input / output
    friend std::istream& operator >>(std::istream &is, modint &x) {
        i64 t; is >> t;
        x = t;
        return (is); 
    }

    friend std::ostream& operator<<(std::ostream &os, const modint &m) {
        return os<<m.val;
    }
};


#line 6 "numerical/combinatoric.hpp"

//fixed mod 
template<i64 mod> class combinatoric {
private:
    using mint = modint<mod>;
    std::vector<mint> fact, inv, ivfact;
    i64 size = 2;

    void update(i64 newsize) {
        if (newsize+1 <= size) return;
        fact.resize(newsize+1);
        inv.resize(newsize+1);
        ivfact.resize(newsize+1);
        for(i32 i = size; i <= newsize; i++) {
            fact[i] = fact[i-1] * i;
            inv[i] = -(inv[mod%i] * (mod/i));
            ivfact[i] = ivfact[i-1] * inv[i];
        }
    }
public:
    combinatoric() : fact(2,1), inv(2,1), ivfact(2,1) {}

    mint nCr(i64 N, i64 R) {
        if (N < R)  return 0;
        if (N < 0 || R < 0) return 0;
        update(N);
        return fact[N] * ivfact[R] * ivfact[N-R];
    }
    mint nPr(i64 N, i64 R) {
        if (N < R)  return 0;
        if (N < 0 || R < 0) return 0;
        update(N);
        return fact[N] * ivfact[N-R];
    }
    mint nHm(i64 N, i64 M) {
        return nCr(N+M-1,M);        
    }
};

//mod not fixed (given as input) for prime mod
struct combinatoric_s {
private:
    std::vector<i64> fact, inv, ivfact;
    i64 mod, size = 2;
    void update(i32 newsize) {
        if (newsize+1 <= size) return;
        fact.resize(newsize+1);
        inv.resize(newsize+1);
        ivfact.resize(newsize+1);
        for(i32 i = size; i <= newsize; i++) {
            fact[i] = fact[i-1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod/i) %mod;
            ivfact[i] = ivfact[i-1] * inv[i] % mod;
        }
        size = newsize+1;
    }
public:
    combinatoric_s(i64 mod) : mod(mod), fact(2,1), inv(2,1), ivfact(2,1) {}
    u64 nCr(i64 N, i64 R) {
        if (R < 0 || N < R || N < 0) return 0;
        update(N);
        return fact[N] * (ivfact[R] * ivfact[N - R] % mod) % mod;
    }
    u64 nPr(i64 N, i64 R) {
        if (R < 0 || N < R || N < 0) return 0;
        update(N);
        return fact[N] * ivfact[R] % mod;
    }
    u64 nHm(i64 N, i64 M) {
        return nCr(N+M-1,M);        
    }
};


#line 1 "numerical/factorize_s.hpp"



#line 1 "numerical/pollard_rho.hpp"



#line 1 "numerical/gcd.hpp"



#line 5 "numerical/gcd.hpp"

template<typename T>
T gcd(T a, T b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}


#line 1 "numerical/miller_rabin.hpp"



#line 7 "numerical/miller_rabin.hpp"

namespace Miller {
    bool isPrime(u64 n) {
        if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
        u64 A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n-1), d = n >> s;
        for (u64 a : A) {
            u64 p = modpow_s(a%n, d, n), i = s;
            while (p != 1 && p != n - 1 && a % n && i--)
                p = modmul(p,p,n);
            if (p != n-1 && i != s) return 0;
        }
        return 1;
    }
}


#line 8 "numerical/pollard_rho.hpp"

//tries to find a factor with probabilistic measures

template <typename T>
T find_prime_factor(T num) {
    if (num%2 == 0) {
        return 2;
    }
    T mx = 1ll + pow(num,0.125);

    for(T c = 1; c < num; c++) {
        auto f = [&](T a) {
            return (T)((modmul(a,a,num) + c)%num); 
        };
        T x = 0, y = 0, g = 1;
        while(g == 1) {
            x = f(x);
            y = f(f(y));
            g = gcd(std::abs(x-y), num);
        }
        if (g == num) continue;
        if (Miller::isPrime(g)) {
            return g;
        }
        else if (Miller::isPrime(num/g)) {
            return num/g;
        }
        else {
            return find_prime_factor(g);
        }
    }
    return num;
}



#line 7 "numerical/factorize_s.hpp"

//pollard rho factorization
template<typename T>
std::vector<std::pair<T,i32>> factorize_s(T num) {
    std::vector<std::pair<T,i32>> ret;
    i32 tmp = ctz(num);
    if (tmp != 0) {
        ret.emplace_back(2,tmp);
    }
    num >>= tmp;
    while(Miller::isPrime(num) == 0 && num != 1) {
        T min_fact = find_prime_factor(num);
        i32 cnt = 0;
        while(num%min_fact == 0) {
            num /= min_fact;
            cnt++;
        }
        ret.emplace_back(min_fact,cnt);
    }
    if (num != 1) {
        ret.emplace_back(num,1);
    }
    sort(ret.begin(),ret.end());

    return ret;
}



#line 1 "numerical/factorize.hpp"



#line 6 "numerical/factorize.hpp"

template<typename T>
std::vector<std::pair<T,i32>> factorize(T num) {
    std::vector<std::pair<T,i32>> ret;
    i32 tmp = ctz(num);
    if (!tmp) {
        ret.emplace_back(2,tmp);
    }
    for(T d = 3; d*d <= num; d += 2) {
        if (num%d == 0) {
            int cnt = 0;
            while(num % d == 0) {
                num /= d;
                cnt++;
            }
            ret.emplace_back(d, cnt);
        }
    }
    if (num != 1) {
        ret.emplace_back(num, 1);
    }
    return ret;
}



#line 1 "numerical/kth_root.hpp"



#line 5 "numerical/kth_root.hpp"

//Kth root modulo P of B is X that satisfies X^K = B (mod P) or -1 if no such value exists





#line 1 "numerical/smallest_prime.hpp"



#line 6 "numerical/smallest_prime.hpp"

struct SPF {
private:
public: 
    std::vector<i64> vec;
    SPF(i64 N) : vec(N+1,-1) {
        for(i64 i = 2; i <= N; i++) {
            if (vec[i] != -1) continue;
            for(i64 j = i; j <= N; j += i) {
                if (vec[j] == -1) {
                    vec[j] = i;
                }
            }
        }
    }
    i64 query(i64 N) {
        return vec[N];
    }
};


#line 43 "apiros3_lib.hpp"


#line 4 "test.cpp"
using namespace std;
using ll = long long;

int main() {
    
    return 0;
}
