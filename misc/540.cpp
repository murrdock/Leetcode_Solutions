class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int m = (l+r)/2;
            if(nums[m] == nums[m^1]) { // to check for even and odd mid index value
                l = m+1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
