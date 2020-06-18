class Solution {
public:
    int m, n;
    string a, b;
    vector<vector<int>> dp;
    int minimumDeleteSum(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        dp.assign(m+1, vector<int> (n+1, -1));
        a = s1, b = s2;
        dp[m][n] = 0;
        return dfs(0,0);
    }
    int dfs(int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];

        if(i == m) {
            return dp[i][j] = b[j] + dfs(i, j+1);
        }
        if(j == n) {
            return dp[i][j] = a[i] + dfs(i+1, j);
        }
        if(a[i] == b[j]) {
            return dp[i][j] = dfs(i+1, j+1);
        }
        return dp[i][j] = min(a[i] + dfs(i+1, j), b[j] + dfs(i, j+1));
    }
};
