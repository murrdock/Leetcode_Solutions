class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0;
        int l = 0, r = l;
        int n = nums.size()-1;
        while(r < n) {
            int reach = r;
            for(int i = l; i <= min(r,n); i++) {
                reach = max(reach, i + nums[i]);
            }
            cnt++;
            l = r+1;
            r = reach;
        }
        return cnt;
    }
};
