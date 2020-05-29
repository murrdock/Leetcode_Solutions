class Solution {
public:
    inline int find(string &s, string &w, int n) {
        for(int i = 0; i < s.length(); i+=n) {
            if(s.substr(i,n) == w) return i;
        }
        return string::npos;
    }
    bool equals(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    bool check(string s, vector<string>& words) {
        int n = words[0].length();
        for(int i = 0; i < words.size(); i++) {
            size_t x = find(s, words[i], n);
            if(x == string::npos) return false;
            s.erase(x, n);
        }
        return true;
    }
    vector<int> findSubstring(string su, vector<string>& words) {

        int n = words.size();
        if(words.size() == 0) return {};
        int l = words[0].length();
        if(l == 0) return {};
        int s = n*l;
        if(su.length() < s) return {};
        vector<int> t(26,0);
        for(auto &str : words) {
            for(auto c : str)
                t[c-'a']++;
        }
        vector<int> ve(26,0);
        vector<int> ans;
        for(int i = 0; i < s-1; i++) {
            ve[su[i]-'a']++;
        }
        for(int i = s-1; i < su.length(); i++) {
            ve[su[i]-'a']++;
            if(equals(t,ve)) {
                if(check(su.substr(i-s+1,s), words)) ans.push_back(i-s+1);
            }
            ve[su[i-s+1]-'a']--;
        }
        return ans;
    }
};
