class Solution {
public:
    int M = 1000000007;
    int kInversePairs(int N, int K) {
        vector<vector<int>> dp(N+1, vector<int> (K+1,0));
        for(int i = 1; i <= N; i++){
            dp[i][0] = 1;
        }
        for(int n = 1; n <= N; n++){
            for(int k = 1; k <= min(n*(n-1)/2,K); k++){
                dp[n-1][k] = (dp[n-1][k] + dp[n-1][k-1])%M;
                if(k <= n-1)
                    dp[n][k] = dp[n-1][k];
                else dp[n][k] = (M + dp[n-1][k] - dp[n-1][k-n])%M;
            }
        }
        return dp[N][K];
    }
};
