#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

/*
Explanation: For n > 1 say n = 2, we have to consider all possibilites which do not overlap.
If you write a normal dfs to generate all possible backtracks you see those that don't overlap.
That can be done other way by considering an array of size 12 with all possibilites(n=1). Then
see for each which are those that don't overlap with it. You can construct an ajd list to not
to check again and again. Now, the problem is simply to write it in a bottom up manner as
even with memoization lot of branches of trees.
*/

class Solution {
public:
    int N = 1000000007;
    int numOfWays(int n) {
        vector<string> ve;
        helper(ve, 0, "");
        vector<int> dp(12,1);
        vector<vector<int>> adj(12, vector<int> ());
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 12; j++) {
                if(!overlap(ve[i],ve[j])) {
                    adj[i].push_back(j);
                }
            }
        }
        for(int i = 2; i <= n; i++) {
            vector<int> tp(12,0);
            for(int i = 0; i < 12; i++) {
                for(auto &x : adj[i]) {
                    tp[i] = (tp[i] + dp[x])%N;
                }
            }
            dp = tp;
        }
        int ans = 0;
        for(int i = 0; i < 12; i++) ans = (ans + dp[i])%N;
        return ans;
    }
    bool overlap(string& a, string& b) {
        for(int i = 0; i < 3; i++) {
            if(a[i] == b[i]) return true;
        }
        return false;
    }
    void helper(vector<string>&ve, int n, string s){
        if(n == 3) {
            ve.push_back(s);
        } else {
            string t = "ryg";
            for(int i = 0; i < t.length(); i++) {
                if(n == 0) {
                    helper(ve, n+1, s+t[i]);
                }
                else if(s.back() != t[i]) {
                    helper(ve, n+1, s+t[i]);
                }
            }
        }
    }
};
