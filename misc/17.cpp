class Solution {
public:
    vector<string> dp;
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return {};
        dp.push_back("abc");
        dp.push_back("def");
        dp.push_back("ghi");
        dp.push_back("jkl");
        dp.push_back("mno");
        dp.push_back("pqrs");
        dp.push_back("tuv");
        dp.push_back("wxyz");
        return dfs(0, digits);
    }
    vector<string> dfs(int s, string digits) {
        if(s == digits.length()) {
            return vector<string>{""};
        }
        int ind = digits[s]-'0' - 2;
        vector<string> t = dfs(s+1, digits);
        string st = dp[ind];
        vector<string> ans;
        for(int i = 0; i < st.length(); i++) {
            for(int j = 0; j < t.size(); j++) {
                ans.push_back(st[i]+t[j]);
            }
        }
        return ans;
    }
};
