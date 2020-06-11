class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<vector<int>> T(n, vector<int> (n));

        for(int l = 1; l <= n; l++){
            for(int i = 0; i <= n-l; i++){
                int j = i+l-1;
                int val = 0;
                for(int k = i; k <= j; k++){
                    int left = 1, right = 1;
                    if(i!=0){
                        left = nums[i-1];
                    }
                    if(j!=n-1){
                        right = nums[j+1];
                    }
                    int before = 0, after = 0;
                    if(k!=i){
                        before = T[i][k-1];
                    }
                    if(k!=j){
                        after = T[k+1][j];
                    }
                    val = max(val, (before + after + left*nums[k]*right));
                }
                T[i][j] = val;
            }
        }
        return T[0][n-1];
    }
};
