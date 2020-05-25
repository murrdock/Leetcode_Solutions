// bottom up solution
class Solution {
public:
    int n;
    int compute(vector<int>& prices) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int r = i+1;
            while(r < n && prices[r] >= prices[r-1]) r++;
            r--;
            if(prices[r] > prices[i]) ans += prices[r] - prices[i];
            i = r;
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        if(k >= n/2) {
            return compute(prices);
        }
        vector<vector<int>> dp(k+1, vector<int> (n, 0));

        for(int t = 1; t <= k; t++) {
            int profit = INT_MIN;
            for(int j = 1; j < n; j++) {
                // this is an important line to reduce complexity
                profit = max(profit, dp[t-1][j-1] - prices[j-1]);

                dp[t][j] = max(dp[t][j-1], prices[j] + profit);
            }
        }
        return dp[k][n-1];
    }
};
