class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xoy = 0;
        for(int i = 0; i < nums.size(); i++){
            xoy = xoy ^ nums[i];
        }
        int x, y;
        x = y = 0;
        int k = xoy & (-1 * xoy);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & k)
                x = x ^ nums[i];
            else
                y = y ^ nums[i];
        }
        return {x,y};
    }
};
