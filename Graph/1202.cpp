#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void make_set(int u) {
        parent[u] = u;
        size[u] = 1;
    }
    int find_set(int u){
        if(parent[u] == u)
            return u;
        return parent[u] = find_set(parent[u]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    vector<vector<char>> ans;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        parent.resize(n);
        size.resize(n);
        for(int i= 0; i < n; i++){
            make_set(i);
        }
        for(int i= 0; i < pairs.size(); i++) {
            union_set(pairs[i][0], pairs[i][1]);
        }
        ans.resize(n, vector<char>());
        for(int i = 0; i < s.length(); i++) {
            int x = find_set(i);
            vector<char>& tmp = ans[x];
            tmp.push_back(s[i]);
        }
        for(auto& x : ans)
            sort(x.begin(),x.end());
        string res(n, ' ');
        for(int i = n-1; i >= 0; i--) {
            vector<char>&tmp = ans[find_set(i)];
            res[i] = tmp.back();
            tmp.pop_back();
        }
        return res;
    }
};
