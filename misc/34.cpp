class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        auto it = lower_bound(nums.begin(),nums.end(),target);

        if(it == nums.end() or *it != target) return {-1,-1};

        int a = distance(nums.begin(),it);

        int b = distance(nums.begin(), upper_bound(nums.begin(),nums.end(),target))-1;

        return {a,b};
    }
};
