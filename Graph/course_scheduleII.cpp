class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>> adj(n, vector<int>());
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool> visit(n, false);
        vector<bool> stack(n, false);

        for(int i = 0; i < n; i++) {
            if(!visit[i]) {
                if(!dfs(i, visit, stack, adj, ans)) return {};
            }
        }
        return ans;
    }

    bool dfs(int u, vector<bool>& visit, vector<bool>& stack, vector<vector<int>>& adj, vector<int>& ans) {
        visit[u] = true;
        stack[u] = true;

        for(auto v : adj[u]) {
            if(stack[v]) return false;
            if(!visit[v]) {
                if(!dfs(v, visit, stack, adj, ans)) return false;
            }
        }
        ans.push_back(u);
        stack[u] = false;
        return true;
    }

};
