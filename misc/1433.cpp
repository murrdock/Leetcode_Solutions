class Solution {
public:
    inline bool check(string& a, string& b) {
        for(int i = 0; i < a.length(); i++) {
            if(a[i] < b[i]) return false;
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        if(s1.length() != s2.length()) return false;

        vector<int> a(26,0), b(26,0);
        for(int i = 0; i < s1.length(); i++) {
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        s1.clear();
        s2.clear();
        for(int i = 0; i < 26; i++) {
            while(a[i]) {
                s1 += string(a[i], i+'a');
                a[i] = 0;
            }
            while(b[i]) {
                s2 += string(b[i], i+'a');
                b[i] = 0;
            }
        }

        if(check(s1,s2) or check(s2, s1)) return true;
        return false;
    }
};
