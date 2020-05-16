class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, INT_MAX);
        dp[0] = 1;

        for(int i = 1; i < n; i++) {
            for(int k = 0; k < primes.size(); k++)
                dp[i] = min(dp[i], find(0,i-1,primes[k],dp));
        }
        return dp[n-1];
    }
    int find(int l, int r, int k, vector<int>& dp){
        long long int ans = INT_MAX;
        int R = r;
        while(l <= r) {
            int m = (l+r)/2;
            if((long long)dp[m] * k > dp[R]) {
                ans = (long long)dp[m]*k;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};
