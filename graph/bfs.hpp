#ifndef GENERAL_BFS 
#define GENERAL_BFS

#include "general/fixed_integer.hpp"
#include <vector>
#include <queue>
#include <limits>

template <typename T>
struct BFS_UW {
private:
    i32 INF = std::numeric_limits<i32>::max();
public:
    std::vector<i32> dist;
    std::vector<T> prev;
    BFS_UW(std::vector<std::vector<T>> adj, i32 start = 0) {
        i32 N = adj.size();
        dist.resize(N,INF);
        prev.resize(N);
        dist[0] = 0;
        std::queue<i64> que;
        que.push(0);
        while(!que.empty()) {
            T top = que.front(); que.pop();
            for(T u : adj[top]) {
                if (dist[u] > dist[top] + 1) {
                    dist[u] = dist[top] + 1;
                    prev[u] = top;
                    que.push(u);
                } 
            }
        }
        for(i32 &u : dist) {
            if (u == INF) u = -1;
        }
    }
};

namespace maze {
    template<typename U, typename T>
    U padding(U& maze, T wall) {
        i32 W = maze[0].size();
        std::vector<T> pad(W+2,wall);
        U new_maze(1,pad);
        for(auto& u : maze) {
            std::vector<T> line(1,wall);
            line.insert(std::end(line), std::begin(u), std::end(u));
            line.push_back(wall);
            new_maze.push_back(line);
        }
        new_maze.push_back(pad);
        return new_maze;
    }
}

template <typename T>
struct Maze {
private:
    i32 H, W;
    i32 INF = std::numeric_limits<i32>::max() / 2;
    std::vector<std::vector<i32>> distance;

    template <typename U, typename V>
    void solve_maze(std::vector<std::vector<T>>& maze, std::pair<U,U> start, T wall, std::vector<V> X, std::vector<V> Y) {
        H = maze.size(), W = maze[0].size();
        distance.resize(H+2,std::vector<i32>(W+2,INF));
        auto new_maze = maze::padding(maze,wall);
        std::queue<std::pair<i32,i32>> que;
        que.push({start.first + 1, start.second + 1});
        distance[start.first + 1][start.second + 1] = 0;

        while(!que.empty()) {
            auto top = que.front(); que.pop();
            i32 i = top.first, j = top.second;
            #include <bits/stdc++.h>
            for(i32 k = 0; k < X.size(); k++) {
                i32 ti = i + X[k], tj = j + Y[k];
                if (new_maze[ti][tj] == wall) continue;
                if (distance[ti][tj] > distance[i][j] + 1) {
                    distance[ti][tj] = distance[i][j] + 1;
                    que.push({ti, tj});
                }
            }
        }
        for(auto &u : distance) for(auto &v : u) {
            if (v == INF) v = -1;
        }
    }
public:
    template <typename U, typename V>
    Maze(std::vector<std::vector<T>>& maze, std::pair<U,U> start = {0,0}, T wall = 1, std::vector<V> X = {1,0,-1,0}, std::vector<V> Y = {0,1,0,-1}) {
        solve_maze(maze,start,wall,X,Y);
    }
    template <typename U>
    Maze(std::vector<std::vector<T>>& maze, std::pair<U,U> start = {0,0}, T wall = 1) {
        std::vector<i32> X = {1,0,-1,0}, Y = {0,1,0,-1};
        solve_maze(maze,start,wall,X,Y);
    }
    template <typename U, typename V>
    Maze(std::vector<std::string>& maze, std::pair<U,U> start = {0,0}, char wall = '#', std::vector<V> X = {1,0,-1,0}, std::vector<V> Y = {0,1,0,-1}) {
        std::vector<std::vector<char>> new_maze;
        for(std::string& u : maze) {
            new_maze.emplace_back(u.begin(), u.end());
        }
        solve_maze(new_maze,start,wall,X,Y);
    }
    template <typename U>
    Maze(std::vector<std::string>& maze, std::pair<U,U> start = {0,0}, char wall = '#') {
        std::vector<std::vector<char>> new_maze;
        for(std::string& u : maze) {
            new_maze.emplace_back(u.begin(), u.end());
        }
        std::vector<i32> X = {1,0,-1,0}, Y = {0,1,0,-1};
        solve_maze(new_maze,start,wall,X,Y);
    }


    template<typename U>
    i32 dist(std::pair<U,U> query) {
        return distance[query.first + 1][query.second + 1];
    }
    template<typename U>
    i32 dist(U queryH, U queryW) {
        return distance[queryH + 1][queryW + 1];
    }
    template<typename U>
    i32 dist(U query) {
        return distance[query/W + 1][query%W + 1];
    }
};

#endif