class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> ve(1000);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 && nums[i] < 1000) {
                ve[nums[i]] = true;
            }
        }
        for(int i = 1; i < ve.size(); i++) {
            if(ve[i] == false) return i;
        }
        return 1000;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size()) return 1;
        int l = 0;
        for(int i = nums.size()-1; i > l; i--) {
            while(nums[l] > 0 && l < i) l++;
            if(nums[i] > 0) {
                swap(nums[i],nums[l]);
            }
        }

        int n = 0;
        while(n < nums.size() && nums[n] > 0) n++;

        for(int i = 0; i < n; i++) {
            if(nums[i] <= n) {
                while(nums[i] != i+1 && nums[i] < n)
                    if(nums[i] != nums[nums[i]-1])
                        swap(nums[i], nums[nums[i]-1]);
                    else break;
            }
        }
        int i;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1) return i+1;
        }

        return i+1;
    }
};
