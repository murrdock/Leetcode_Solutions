class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void make_set(int u) {
        parent[u] = u;
        size[u] = 0;
    }
    int find_set(int u){
        if(parent[u] == u) return u;
        return parent[u] = find_set(parent[u]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> factors(n, vector<int> ());
        set<int> s;
        for(int i = 0; i < A.size(); i++){
            int x = A[i];
            int d = 2;
            while(d * d <= x) {
                if(x%d == 0) {
                    while(x % d == 0) x /= d;
                    factors[i].push_back(d);
                    s.insert(d);
                }
                d++;
            }
            if(x > 1 or !factors[i].size()){
                factors[i].push_back(x);
                s.insert(x);
            }
        }

        int L = *s.rbegin();
        parent.resize(L+1);
        size.resize(L+1);
        for(auto &a : s)
            make_set(a);

        for(auto &arr : factors){
            int p = find_set(arr[0]);
            size[p]++; // add A[i] to a set hence increase the count
            for(auto &x : arr)
                union_set(arr[0], x);
        }
        return *max_element(size.begin(),size.end());
    }
};
