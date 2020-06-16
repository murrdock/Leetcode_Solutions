class Solution {
public:
    using lo = long long int;
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<lo, lo>> dp(n);
        lo ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                lo d = lo(A[i]) - lo(A[j]);
                lo s = 0;
                if(dp[j].find(d) != dp[j].end()) {
                    s = dp[j][d];
                }
                ans += s;
                dp[i][d] += s + 1;
            }
        }
        return (int)ans;
    }
};
