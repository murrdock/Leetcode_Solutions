class Solution {
public:

  // store different values of difference at each index
    int longestArithSeqLength(vector<int>& A) {
        int x = *max_element(A.begin(),A.end());
        int n = A.size();
        vector<vector<int>> dp(n, vector<int> (2*x+1,0));
        int ans = 0;
        for(int i = A.size()-2; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                int d = x + A[j]-A[i];
                dp[i][d] = max(1+dp[j][d], dp[i][d]);
                ans = max(ans, dp[i][d]);
            }
        }
        return ans+1;
    }
};
