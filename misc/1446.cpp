class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        int r;
        for(int l = 0; l < s.length(); l++) {
            r = l;
            while(r < s.length() && s[r] == s[l]) r++;
            ans = max(ans, r-l);
            l = r-1;
        }
        return ans;
    }
};
