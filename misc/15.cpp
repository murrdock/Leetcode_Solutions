class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};

        vector<vector<int>> res;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                int val = nums[i] + nums[l] + nums[r];
                if(val == 0) {
                    vector<int> ve = {nums[i], nums[l], nums[r]};
                    while(nums[l] == ve[1] && l < r) l++;
                    while(nums[r] == ve[2] && l < r) r--;
                    res.push_back(ve);
                    if(l >= r) break;
                }
                else if (val > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
};
