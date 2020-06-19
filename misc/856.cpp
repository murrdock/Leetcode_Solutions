class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<string> bal;
        int l = 0, pos = 0;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '(') l++;
            else l--;
            if(l == 0) {
                bal.push_back(S.substr(pos, i-pos+1));
                pos = i+1;
            }
        }
        int ans = 0;
        for(auto a : bal) {
            if(a.length() == 2) ans += 1;
            else ans += 2 * scoreOfParentheses(a.substr(1,a.length()-2));
        }
        return ans;
    }
};
