class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int l = 0, n = nums.size();
        while(l < n) {
            if(nums[l]) break;
            else l++;
        }
        for(int r = l+1; r < n; r++) {
            if(nums[r]) {
                if(r - l <= k) return false;
                l = r;
            }
        }
        return true;
    }
};
