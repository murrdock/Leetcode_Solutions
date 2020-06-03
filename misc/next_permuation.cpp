class Solution {
private:
    template <class T> void swapp ( T& a, T& b )
    {
        T c(a); a=b; b=c;
    }

public:
    void nextPermutation(vector<int>& nums) {
        bool t = false;
        //find the next greater number than the given number
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int min = nums[i], x = i;
                for(int j = i; j < nums.size(); j++)
                    if(nums[j] > nums[i-1] && nums[j] < min){
                        min = nums[j]; x = j;
                    }
                swapp(nums[i-1], nums[x]);
                std::sort(nums.begin()+i,nums.end());
                t = true;
                break;
            }
        }
        if(!t){
            // sorting a sequence in ascending order which is already in descending order
            int l = 0; int r = nums.size()-1;
            while(l <= r){
                swap(nums[l],nums[r]);
                l++; r--;
            }
        }
    }
};
