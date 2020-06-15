class Solution {
public:
    int longestSubstring(string s, int k) {

        if(!s.length()) return 0;

        vector<int> ve(26, 0);

        for(int i = 0; i < s.length(); i++) ve[s[i]-'a']++;

        for(auto &x : ve) if(x < k) x = 0;


        int ans = 0, r = 0, l = 0;

        for(r = 0; r < s.length(); r++) {
            if(ve[s[r]-'a'] == 0) {
                ans = max(ans, longestSubstring(s.substr(l, r-l), k));
                l = r+1;
            }
        }

        if(l == 0 && r == s.length()) return s.length();

        ans = max(ans, longestSubstring(s.substr(l), k));

        return ans;

    }
};
