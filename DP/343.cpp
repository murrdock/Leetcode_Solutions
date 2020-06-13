class Solution {
public:
    int integerBreak(int n) {
        if(n == 1) return 0;
        else if(n == 2) return 1;
        else if(n == 3) return 2;
        else if(n == 4) return 4;

        static int dp[59];
        fill(dp, dp+59, -1);
        dp[1] = 1; dp[2] = 2; dp[3] = 3;
        if(dp[n] == -1) helper(dp, n);
        return dp[n];
    }
    int helper(int dp[], int n) {
        int ans = 0;
        if(dp[n] != -1) return dp[n];
        for(int i = 1; i <= n/2; i++) {
            ans = max(ans, helper(dp, i) * helper(dp, n-i));
        }
        return dp[n] = ans;
    }
};
