// Buy and sell stock with cooldown
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int s1 = 0,
        s2 = -prices[0],
        s3 = INT_MIN;
        int ps1, ps2;
        for(int i = 1; i < n; i++) {
            ps1 = s1, ps2 = s2;
            s1 = max(s1, s3);
            s2 = max(s2, ps1-prices[i]);
            s3 = ps2 + prices[i];
        }
        return max(s1, s3);
    }
};
