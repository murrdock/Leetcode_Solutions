class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void make_set(int u) {
        parent[u] = u;
        size[u] = 1;
    }
    int find_set(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_set(parent[u]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a,b);
            size[a] += size[b];
            parent[b] = a;
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++) make_set(i);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(M[i][j]) union_set(i,j);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) ans++;
        }
        return ans;
    }
};
