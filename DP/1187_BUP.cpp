class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<vector<int>> dp(n, vector<int> (n+1, INT_MAX));
        sort(arr2.begin(),arr2.end());
        dp[0][0] = arr1[0];
        dp[0][1] = min(arr1[0],arr2[0]);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(dp[i-1][j] < arr1[i]) {
                    dp[i][j] = min(dp[i][j], arr1[i]);
                }
                dp[i][j+1] = min(dp[i][j+1], find(arr2, dp[i-1][j]));
            }
        }
        for(int j = 0; j <= n; j++) {
            if(dp[n-1][j] < INT_MAX)
                return j;
        }
        return -1;
    }
    int find(vector<int>& arr, int val) {
        int l = 0, r = arr.size()-1;
        int ans = -1;
        while(l <= r) {
            int m = (l+r)/2;
            if(arr[m] > val) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans == -1 ? INT_MAX : arr[ans];
    }
};
