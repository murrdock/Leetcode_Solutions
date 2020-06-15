class Solution {
public:
    #define B 6000
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2) return false;
        sum = sum/2;
        vector<bool> b(sum+1);
        b[0] = true;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > sum) return false;
            if(nums[i] == sum) return true;
            for(int j = sum; j >= nums[i]; j--) {
                b[j] = b[j] || b[j-nums[i]];
            }
        }
        return b[sum];
    }
};
