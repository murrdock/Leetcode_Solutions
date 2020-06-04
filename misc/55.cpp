class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l_ind = nums.size()-1;
        bool curr = false;
        for(int i = nums.size()-1; i >= 0; i--) {
            if(i+nums[i] >= l_ind) {
                l_ind = i;
                curr = true;
            } else {
                curr = false;
            }
        }
        return curr;
    }
};
