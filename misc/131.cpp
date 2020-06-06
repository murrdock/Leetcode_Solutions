class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> man(s.length(), vector<int>());
        int N = 2 * s.length()-1;

        for(int i = 0; i < N; i++) {
            int left = i/2;
            int right = left + i%2;
            while(left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
                man[left].push_back(right);
                left--;right++;
            }
        }
        vector<string> curr;
        vector<vector<string>> ans;

        dfs(0, s, man, ans, curr);
        return ans;
    }
    void dfs(int ind, string& s, vector<vector<int>>& man, vector<vector<string>>& ans, vector<string>& curr) {
        if(ind == s.length()) {
            ans.push_back(curr);
            return;
        }

        for(auto v : man[ind]) {
            curr.push_back(s.substr(ind, v-ind+1));
            dfs(v+1, s, man, ans, curr);
            curr.pop_back();
        }
    }
};
