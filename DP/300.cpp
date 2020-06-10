class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        // for O(nlogn)
        for(int x : nums) {
            auto it = lower_bound(dp.begin(),dp.end(),x);
            if(it == dp.end()) {
                dp.push_back(x);
            } else {
                *it = x;
            }
        }
        return dp.size();
    }
};
