class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int>& nums = height;
        int l = 0, n = height.size();
        while(l < n) {
            while(l+1 < n) {
                if(height[l+1] >= height[l]) l++;
                else break;
            }
            if(l+1 == n) break;
            int r = l+1;
            int val = 0;
            while(r < n && nums[r] < nums[l]) {
                val += nums[l]-nums[r];
                r++;
            }
            if(r == n) {
                vector<int> tmp(height.begin()+l, height.end());
                reverse(tmp.begin(),tmp.end());

                ans += trap(tmp);
                break;
            } else {
                ans += val;
                l = r;
            }
        }
        return ans;
    }
};
