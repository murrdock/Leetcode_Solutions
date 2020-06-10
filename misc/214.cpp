// Shortest Palindrome
class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        t = s + "#" + t;
        int n = t.length();

        vector<int> dp(n,0);

        for(int i = 1; i < n; i++) {
            int j = dp[i-1];
            while(j > 0 && t[j] != t[i]) j = dp[j-1];
            if(t[j] == t[i]) j++;
            dp[i] = j;
        }

        int u = dp[n-1];
        string a = s.substr(u);
        reverse(a.begin(),a.end());
        return a + s;
    }
};
