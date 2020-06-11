// Coin change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,10000);
        dp[0] = 0;
        for(auto x : coins) {
            for(int i = x; i <= amount; i++) {
                dp[i] = min(dp[i], 1 + dp[i-x]);
            }
        }
        if(dp[amount] == 10000) return -1;
        return dp[amount];
    }
};
