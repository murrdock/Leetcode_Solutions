class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int p = abs(nums[i])-1;
            if(nums[p] < 0) res.push_back(p+1);
            nums[p] = -1 * nums[p];
        }
        return res;
    }
};
