class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> ve = nums;
        for(int i = 0; i < ve.size(); i++){
            if(ve[i] == 0) ve[i] = -1;
        }
        int n = ve.size();
        int sum = n;
        vector<int> m(2*n+1,50005);
        m[n] = -1;
        int ans = 0;
        for(int i = 0; i < ve.size(); i++){
            sum += ve[i];
            if(m[sum] != 50005){
                ans = max(ans, i-m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return ans;
    }
};
