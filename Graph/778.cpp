#include<bits/stdc++.h>
using namespace std;

// binary-search + DFS Solution
class Solution {
public:
    int n;
    int target;
    vector<int> value;
    vector<vector<int>> dir = {{-1,0},{+1,0},{0,-1},{0,+1}};
    bool valid(int x,int y){
        return (x >= 0 && x < n) && (y >= 0 && y < n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        value.resize(n*n);
        vector<vector<int>> adj(n*n, vector<int>());
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                int u = n*i+j;
                value[u] = grid[i][j];
                for(auto arr : dir){
                    int x = arr[0]+i;
                    int y = arr[1]+j;
                    if(valid(x,y)){
                        int v = n*x+y;
                        adj[u].push_back(v);
                    }
                }
            }
        }
        target = n*n-1;
        vector<bool> visit;
        int ans = -1;
        int l = 0, r = target;
        while(l <= r) {
            int m = (l+r)/2;
            visit.clear();
            visit.assign(n*n,false);
            if(dfs(adj,0,m,visit)){
                r = m-1;
                ans = m;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& adj, int u, int T, vector<bool>& visit){
        if(value[u] > T) return false;
        if(u == target && T >= value[u]) return true;
        visit[u] = true;
        for(auto v : adj[u]){
            if(!visit[v])
                if(dfs(adj,v,T,visit))
                    return true;
        }
        return false;
    }
};

// Dijkstra's with distance between u->v is max{dist[u],value[v]}
class Solution {
public:
    int n;
    int target;
    vector<int> value;
    vector<int> dist;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    bool valid(int x,int y){
        return (x >= 0 && x < n) && (y >= 0 && y < n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        value.resize(n*n);
        target = n*n-1;
        dist.assign(n*n,n*n*n*n);
        vector<vector<int>> adj(n*n, vector<int>());
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                int u = n*i+j;
                value[u] = grid[i][j];
                for(auto arr : dir){
                    int x = arr[0]+i;
                    int y = arr[1]+j;
                    if(valid(x,y)){
                        int v = n*x+y;
                        adj[u].push_back(v);
                    }
                }
            }
        }
        dist[0] = value[0];
        set<pair<int,int>> s; // <dist,node>
        s.insert({dist[0],0});
        int ans = -1;
        while(s.size()){
            int u = s.begin()->second;
            s.erase(s.begin());
            if(u == target) break;
            for(auto v : adj[u]){
                if(distance(u,v) < dist[v]){
                    s.erase({dist[v],v});
                    dist[v] = distance(u,v);
                    s.insert({dist[v],v});
                }
            }
        }
        return dist[target];
    }
    int distance(int u, int v){
        return max(dist[u], value[v]);
    }
};
