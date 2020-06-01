class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};

        vector<vector<int>> res;

        sort(nums.begin(),nums.end());
        for(int k = 0; k < nums.size()-3; k++) {
            if(k > 0 && nums[k] == nums[k-1]) continue;
            for(int i = k+1; i < nums.size()-2; i++) {
                if(i > k+1 && nums[i] == nums[i-1]) continue;
                int l = i+1, r = nums.size()-1;
                while(l < r) {
                    int val = nums[k] + nums[i] + nums[l] + nums[r];
                    if(val == target) {
                        vector<int> ve = {nums[k], nums[i], nums[l], nums[r]};
                        while(nums[l] == ve[2] && l < r) l++;
                        while(nums[r] == ve[3] && l < r) r--;
                        res.push_back(ve);
                        if(l >= r) break;
                    }
                    else if(val > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
