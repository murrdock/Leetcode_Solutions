// Best time to buy and sell stock IV
class Solution {
public:
    int n;
    vector<int> price;
    vector<vector<vector<int> > > dp;
    int dfs(int s, int k, bool state) {
        if(k == 0 or s == n) {
            return 0;
        }
        if(dp[s][k][state] != -1) return dp[s][k][state];
        if(state) { // sell or hold
            return dp[s][k][state] = max(price[s] + dfs(s+1,k-1,!state), dfs(s+1,k,state));
        } else {  // buy or hold
            return dp[s][k][state] = max(dfs(s+1,k,!state) - price[s], dfs(s+1,k, state));
        }
    }
    int compute(vector<int>& price) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int r = i+1;
            while(r < n && price[r] >= price[r-1]) r++;
            r--;
            if(price[r] - price[i] > 0) ans += price[r] - price[i];
            i = r;
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        if(k >= n/2) {
            return compute(prices);
        }

        k = min(k, n/2);

        dp.assign(n, vector<vector<int>> (k+1, vector<int> (2, -1)));
        price = prices;
        int ans = dfs(0, k, false);
        return ans;
    }
};

// bottom up manner
class Solution {
public:
    int n;
    inline int compute(vector<int>& prices) {
        int ans = 0;
        for(int i = 0; i+1 < n; i++) {
            if(prices[i] < prices[i+1]) ans += prices[i+1]-prices[i];
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
