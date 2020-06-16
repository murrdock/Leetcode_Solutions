class Solution {
public:

    inline bool isEqual(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(!p.length() or p.length() > s.length()) return ans;

        vector<int> vp(26,0), vs(26,0);

        for(int i = 0; i < p.length(); i++) vp[p[i]-'a']++;

        for(int i = 0; i < p.length()-1; i++) vs[s[i]-'a']++;

        for(int i = p.length()-1; i < s.length(); i++) {
            vs[s[i]-'a']++;
            if(isEqual(vs,vp)) ans.push_back(i+1-p.length());
            vs[s[i+1-p.length()]-'a']--;
        }
        return ans;
    }
};
