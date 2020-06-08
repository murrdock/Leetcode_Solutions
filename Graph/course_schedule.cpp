class Solution {
public:
    vector<bool> visit;
    vector<bool> stack;
    bool canFinish(int n, vector<vector<int>>& edge) {
        vector<vector<int>> adj(n, vector<int>());
        for(int i = 0; i < edge.size(); i++) {
            adj[edge[i][0]].push_back(edge[i][1]);
        }
        visit.assign(n, false);
        stack.assign(n, false);
        for(int i = 0; i < n; i++) {
            if(!visit[i]) {
                if(!dfs(i, adj)) return false;
            }
        }
        return true;
    }
    bool dfs(int u, vector<vector<int>>& adj) {
        visit[u] = true;
        stack[u] = true;

        for(auto v : adj[u]) {
            if(stack[v]) return false;
            if(!visit[v]) {
                if(!dfs(v, adj)) return false;
            }
        }
        stack[u] = false;
        return true;
    }

};
