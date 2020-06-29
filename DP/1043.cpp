class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();

        vector<int> dp(n);
        dp[0] = A[0];

        int value = A[0];
        for(int i = 1; i < A.size(); i++){
            if(i >= K){
                int val = A[i];
                for(int j = 1; j <= K; j++){
                    val = max(val, A[i-j+1]);
                    dp[i] = max(dp[i], dp[i-j] + val*j);
                }
            } else {
                value = max(value, A[i]);
                dp[i] = value*(i+1);
            }
        }
        //for(auto &x : dp) cout << x << " ";
        return dp[n-1];
    }
};
