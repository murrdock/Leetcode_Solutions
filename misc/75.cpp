class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        for(int i = 0; i < nums.size(); i++) {

            while(r > l && nums[r] == 2) r--;
            while(l < r && nums[l] == 0) l++;

            if(i < r && nums[i] == 2) {
                swap(nums[i], nums[r]);
            }
            if(i > l && nums[i] == 0) {
                swap(nums[i], nums[l]);
            }
        }
    }
};
