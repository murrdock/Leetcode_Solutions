class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(!nums.size()) return 0;
        int p = 1, n = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                p = max(p, n+1);
            }
            if(nums[i] < nums[i-1]) {
                n = max(n, p+1);
            }
        }
        return max(p,n);
    }
};
