#ifndef CHAR_TRIE
#define CHAR_TRIE

#include <vector>
#include <map>
#include "general/fixed_integer.hpp"

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
            if (!(cur->child).count(u)) {
                (cur->child)[u] = Trie(cur->depth + 1);
            }
            cur = &(cur->child)[u];
        }
        return *cur;
    }

    T dfs_T(Trie cur, T(*func)(), T(*eval)()) {
        T ret = func(cur);
        for(auto u : (cur->child)) {
            ret = eval(ret,dfs_T(u.second,func,eval));
        }
        return ret;
    }
    void dfs_T(Trie cur, T(*func)(), bool(*cond)(),  std::vector<T> &vec) {
        vec.emplace_back(func(cur));
        if (cond(cur)) {
            for(auto u : (cur->child)) {
                dfs_T(u.second, func, cond, vec);
            }
        }
        return;
    }

    i64 dfs_i64(Trie cur, i64(*func)(), i64(*eval)) {
        i64 ret = func(cur);
        for(auto u : (cur->child)) {
            ret = eval(ret,dfs_i64(u.second,func));
        }
        return ret;
    }
    void dfs_i64(Trie cur, i64(*func)(), bool(*cond)(),  std::vector<i64> &vec) {
        vec.emplace_back(func(cur));
        if (cond(cur)) {
            for(auto u : (cur->child)) {
                dfs_i64(u.second, func, cond, vec);
            }
        }
        return;
    }

public:
    Char_Trie(T zero, T one) : zero(zero), one(one) {}

    T count(std::string& S) {
        Trie loc = find(S);
        if (loc == NULL) return zero;
        return loc.count;
    }
    i64 child_count(std::string& S) {
        Trie loc = find(S);
        return loc.child.size();
    }
    void insert(std::string &S, T counter) {
        Trie loc = find_s(S);
        loc.count += counter;
    }
    void erase(std::string S, T counter) {
        char tmp = S.back();
        S.pop_back();
        Trie loc = find(S);
        if (loc.child.count(tmp) != NULL) {
            loc.child[tmp].count -= counter;
            if (loc.child[tmp].count <= zero) {
                loc.child.erase(tmp);
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
            return cur.count;
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


#endif