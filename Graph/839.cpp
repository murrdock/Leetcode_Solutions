#include <bits/stdc++.h>
using namespace std;

// Standard DSU implementation considering all possible edges n*(n-1)/2
// suppose i mathces k and j matches k then both should belong to smae set. Therefore union whenever equal.

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void make_set(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find_set(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = find_set(parent[u]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        make_set(n);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(find_set(i) == find_set(j)) continue; // No need to compare if belong to the same set
                if(equal(A[i],A[j])) {
                    union_set(i,j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i) ans++;
        }
        return ans;
    }
    bool equal(string& a, string& b) {
        int l = 0;
        for(int i = 0;i < a.length(); i++) {
            l = l + (a[i] == b[i] ? 0 : 1);
            if(l > 2) return false;
        }
        return true;
    }
};
