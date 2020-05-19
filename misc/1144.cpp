class Solution {
public:
    int helper(vector<int> nums, int s) {
        int emoves = 0;
        for(int i = s; i < nums.size(); i+=2) {
            if(i == 0) {
                int d = nums[i+1]-nums[i];
                if(d >= 0) {
                    emoves += d + 1;
                    nums[i+1] = nums[i+1] - d - 1;
                }
            }else if (i == nums.size()-1) {
                int d = nums[i-1] - nums[i];
                if(d >= 0) {
                    emoves += d + 1;
                }
            } else {
                int d = nums[i-1] - nums[i];
                if(d >= 0) {
                    emoves += d + 1;
                }
                d = nums[i+1] - nums[i];
                if(d >= 0) {
                    emoves += d + 1;
                    nums[i+1] = nums[i+1] - d - 1;
                }
            }
        }
        return emoves;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(helper(nums, 0), helper(nums,1));
    }
};
