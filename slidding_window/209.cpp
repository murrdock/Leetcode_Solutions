class Solution {
public:
   int binary_search(vector<int>& arr, int l, int right, int key){
        int ans = -1;
        int r = right;
        while(l <= r){
            int m = (l+r)/2;
            if(arr[m] <= key){
                ans = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if(ans == -1) return INT_MAX;
        return right - ans;
    }

    int minSubArrayLen(int s, vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        if(nums[0] >= s) return 1;
        int ans = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            ans = min(ans, binary_search(nums, 0, i, nums[i]-s));
        }
        return ans == INT_MAX ? 0 : ans;

    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while(sum >= s) {
                ans = min(ans, r-l+1);
                sum = sum - nums[l];
                l++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
