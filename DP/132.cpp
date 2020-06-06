class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        for(int i = 0; i <= n; i++) dp[i] = i-1;

        for(int i = 0; i < n; i++) {
            // odd length
            int left = i, right = i;

            while(left >= 0 && right < n && s[left] == s[right]) {
                dp[right+1] = min(dp[right+1], 1 + dp[left]);
                left--; right++;
            }

            //even length
            left = i, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                dp[right+1] = min(dp[right+1], 1 + dp[left]);
                left--; right++;
            }

        }
        return dp[n];
    }
};
