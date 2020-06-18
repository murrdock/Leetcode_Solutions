class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void make_set(int u){
        parent[u] = u;
        size[u] = 1;
    }
    int find_set(int v){
        if(parent[v] == v)
            return v;
        return parent[v] = find_set(parent[v]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 1; i <= n; i++){
            make_set(i);
        }
        vector<int> ans;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int a = find_set(u);
            int b = find_set(v);
            if(a != b){
                if(size[a] > size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
            } else {
                return edges[i];
            }
        }
        return ans;
    }
};
