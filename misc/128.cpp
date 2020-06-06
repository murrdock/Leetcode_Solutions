class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size()==1) return 1;
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(s.count(nums[i]-1)>0) continue;
            int t = nums[i];
            int it = 1;
            while(s.count(++t)>0){
                it++;
            }
            if(count < it) count = it;
        }
        //s.clear();
        return count;
    }
};
