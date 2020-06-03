class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n-1);
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            int x = i;
            while(x < s.length() && s[x] == c) x++;
            ans.push_back(x-i+'0');
            ans.push_back(c);
            i = x-1;
        }
        return ans;
    }
};
