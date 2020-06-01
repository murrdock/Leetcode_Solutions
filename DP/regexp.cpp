class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> T(m+1, vector<bool> (n+1, false));
        T[0][0] = true;
        for(int j = 1; j <= n; j++) {
            if(p[j-1] == '*') T[0][j] = T[0][j-2];
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == p[j-1] or p[j-1] == '.') {
                    T[i][j] = T[i-1][j-1];
                } else if(p[j-1] == '*') {
                    T[i][j] = T[i][j-2] ? true : (s[i-1] == p[j-2] or p[j-2] == '.' ? T[i-1][j] : false);
                }
            }
        }
        return T[m][n];
    }
};
