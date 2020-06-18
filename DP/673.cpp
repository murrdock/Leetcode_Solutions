class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        vector<int> dp(n, 1), counts(n,1);
        for(int j = 0; j < n; j++){
            for(int i = j-1; i >= 0; i--){
                if(nums[i] < nums[j]){
                    if(dp[i] >= dp[j]){
                        dp[j] = dp[i]+1;
                        counts[j] = counts[i];
                    } else if(dp[i]+1 == dp[j]) {
                        counts[j] += counts[i];
                    }
                }
            }
        }
        int l = *max_element(dp.begin(),dp.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == l){
                ans += counts[i];
            }
        }
        return ans;
    }
};
