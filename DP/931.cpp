class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> ve(A[n-1]);
        ve.push_back(A[n-1].back());
        ve.insert(ve.begin(), A[n-1].front());
        for(int i = n-2; i >= 0; i--) {
            vector<int> dp(ve);
            for(int j = 1; j <= n; j++) {
                dp[j] = A[i][j-1] + min(ve[j], min(ve[j-1], ve[j+1]));
            }
            dp[0] = dp[1];
            dp[n+1] = dp[n];
            ve = dp;
        }
        return *min_element(ve.begin(),ve.end());
    }
};
