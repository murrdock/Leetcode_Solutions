class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        vector<int> ve(s.length());
        ve[s.length()-1] = m[s[s.length()-1]];
        for(int i = s.length()-2; i >= 0; i--) {
            if(m[s[i]] < m[s[i+1]]) {
                ve[i] = -1*m[s[i]];
            } else {
                ve[i] = m[s[i]];
            }
        }
        int ans = 0;
        for(auto x : ve) ans += x;
        return ans;
    }
};
