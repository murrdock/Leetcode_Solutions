class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%k or k == 0) return false;
        s = s/k;
        if(*max_element(nums.begin(),nums.end()) > s) return false;
        bitset<16> b(0);
        return dfs(nums, b, k, 0, 0, s);
    }
    bool dfs(vector<int>& nums, bitset<16>& vi, int k, int pos, int curr, const int &sum) {
        if(k == 0) return true;

        if(curr == sum) return dfs(nums, vi, k-1, 0, 0, sum);

        for(int i = pos; i < nums.size(); i++) {
            if(!vi.test(i) && curr + nums[i] <= sum) {
                vi.set(i);
                if(dfs(nums, vi, k, i+1, curr + nums[i], sum)) return true;
                vi.reset(i);
            }
        }
        return false;
    }
};
