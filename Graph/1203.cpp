#include <bits/stdc++.h>

using namespace std;

// Find graph of groups and see if they can have a topological ordering i.e. no cycle.
// For each group have graph of it's elements and see if each has a topological ordering
// Consider directed graphs
// Each Group is a node in a group of graphs which itself contain a graph within it.

class Group{
    map<int, vector<int>> m;
    vector<int> ans;
public:
    Group() {
    }
    int size(){
        return m.size();
    }
    vector<int>& answer(){
        return ans;
    }
    void insert(int u) {
        m[u] = {};
    }
    void add_Edge(int u, int v) {
        m[u].push_back(v);
    }
    bool topologicalSort(vector<bool>& visit, vector<bool>& stack) {
        for(auto it = m.begin(); it != m.end(); it++){
            int u = it->first;
            if(!visit[u]) {
                if(dfs(visit, stack,u))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<bool>&visit, vector<bool>& stack, int u) {
        visit[u] = true;
        stack[u] = true;
        vector<int>& adj = m[u];
        for(auto v : adj) {
            if(stack[v]) return true;
            if(!visit[v])
                if(dfs(visit, stack, v))
                    return true;
        }
        stack[u] = false;
        ans.push_back(u);
        return false;
    }
};
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        m = n+1;
        for(int i = 0;i < n; i++){ // assign unique group id's that belong to no group
            if(group[i] == -1)
                group[i] = m++;
        }
        vector<vector<int>>& adj = beforeItems;
        vector<Group> ve(m);

        for(int i = 0; i < n; i++){
            ve[group[i]].insert(i);
        }
        // adjacency list of graph of Groups
        vector<vector<int>> Gadj(m);
        for(int i = 0; i < n; i++) {
            int u = group[i];
            for(auto v : adj[i]) {
                if(group[v] == u){
                  //if they belong to same group
                    ve[u].add_Edge(i, v);
                } else {
                  // else it's a path from one group to another group
                    Gadj[u].push_back(group[v]);
                }
            }
        }

        vector<bool> visit(m, false);
        vector<bool> stack(m, false);
        vector<int> list;
        for(int i = 0; i < m; i++){
            if(ve[i].size())
                if(!visit[i])
                    if(dfs(visit, stack, Gadj, list, i))
                        return {};
        }

        visit.clear();
        stack.clear();
        visit.assign(n,false);
        stack.assign(n,false);

        for(int i = 0; i < m; i++){
            if(ve[i].size()){
                if(ve[i].topologicalSort(visit,stack))
                    return {};
            }
        }

        vector<int> res(n);
        int ind = 0;
        for(auto i : list) {
            if(ve[i].size()) {
                vector<int>& tmp = ve[i].answer();
                for(int j = 0; j < tmp.size(); j++)
                    res[ind++] = tmp[j];
            }
        }
        return res;
    }
    // used for finding  topological ordering of group of Graphs
    bool dfs(vector<bool>& visit, vector<bool>&stack, vector<vector<int>>& adj, vector<int>& ans, int u){
        visit[u] = true;
        stack[u] = true;
        for(auto v : adj[u]){
            if(stack[v]) return true;
            if(!visit[v])
                if(dfs(visit, stack, adj, ans, v))
                    return true;
        }
        stack[u] = false;
        ans.push_back(u);
        return false;
    }
};
