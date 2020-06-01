class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int ans;
        int val;
        sort(nums.begin(), nums.end());
        for(int j = nums.size()-1; j > 1; j--) {
            int a = nums[j];
            int l = 0, r = j-1;
            while(l < r) {
                val = a + nums[l] + nums[r];
                if(val == target) return target;
                if(diff > abs(val - target)) {
                    diff = abs(val - target);
                    ans = val;
                }
                if(val > target) r--;
                else l++;
            }
        }
        return ans;
    }
};
