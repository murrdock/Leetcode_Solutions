#include <bits/stdc++.h>
using namespace std;

/*
Explanation : Do DFS and for a value from 1 to 4 see if any other adjacent node is not having
that color value, then assign that to it.
*/

class Solution {
public:
    vector<bool> visit;
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> adj(N+1, vector<int> ());
        visit.assign(N+1, false);
        vector<int> res(N+1, 0);
        for(int i = 0; i < paths.size(); i++) {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        for(int i = 1; i <= N; i++) {
            if(!visit[i]) {
                dfs(adj, i, res);
            }
        }
        res.erase(res.begin());
        return res;
    }
    void dfs(vector<vector<int>>& adj, int u, vector<int>& res) {
        visit[u] = true;
        for(int x = 1; x < 5; x++) {
            bool stat = true;
            for(auto& v : adj[u]) {
                if(res[v] == x) {
                    stat = false; break;
                }
            }
            if(stat) {
                res[u] = x;
                break;
            }
        }
        for(auto& v : adj[u]) {
            if(!visit[v])
                dfs(adj, v, res);
        }
    }
};
