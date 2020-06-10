class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(!matrix.size() or !matrix[0].size()) return 0;
        int n = matrix[0].size();
        int ans = 0;
        vector<int> dp (n,0);
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == '1') dp[i] = 1;
            ans = max(ans, dp[i]);
        }

        for(int i = 1; i < matrix.size(); i++) {
            int prev = dp[0];
            if(matrix[i][0] == '1') dp[0] = 1; else dp[0] = 0;
            ans = max(ans, dp[0]);
            for(int j = 1; j < n; j++) {
                int t = dp[j];
                if(matrix[i][j] == '1') {
                    dp[j] = 1 + min(prev, min(dp[j-1], t));
                }
                else dp[j] = 0;
                ans = max(ans, dp[j]);
                prev = t;
            }
        }
        return ans*ans;
    }
};
