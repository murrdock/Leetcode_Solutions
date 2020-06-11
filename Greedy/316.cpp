class Solution {
public:
    int search(string &s, int start, char c) {
        int ans = 1000;
        for(int i = start; i <= s.length(); i++) {
            if(s[i] == c) {
                ans = i; break;
            }
        }
        return ans;
    }
    inline bitset<26> OR(bitset<26> a, bitset<26> b) {
        bitset<26> res;
        for(int i = 0; i < 26; i++) {
            if(a.test(i) or b.test(i)) res.set(i);
        }
        return res;
    }
    string removeDuplicateLetters(string text) {
        vector<bitset<26>> dp(text.length(), 0);
        bitset<26> b(0);

        for(int i = text.size()-1; i >= 0; i--) {
            b.set(text[i]-'a');

           dp[i] = b;
        }

        bitset<26> t;
        int pos = 0;
        string res = "";
        while(t != b) {
            for(int i = 0; i < 26; i++) {
                if(b.test(i) && !t.test(i)) {
                    int x = search(text, pos, 'a'+i);
                    if(OR(t,dp[x]) == b) {
                        t.set(i);
                        res.push_back('a'+i);
                        pos = x+1;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
