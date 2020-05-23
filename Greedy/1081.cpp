class Solution {
public:

    string smallestSubsequence(string text) {
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
