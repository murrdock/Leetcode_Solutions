class Solution {
public:
    unordered_map<string, string> list;
    bool ans = false;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(int i = 0; i < allowed.size(); i++){
            list[allowed[i].substr(0,2)].push_back(allowed[i][2]);
        }
        dfs(bottom, 0, "");
        return ans;
    }
    void dfs(string base, int s, string newbase) {
        if(ans) return;
        if(base.length() == 1) ans = true;
        if(s == base.length()-1) {
            dfs(newbase, 0, "");
        }
        string st = list[base.substr(s,2)];
        if(st.length() == 0) return;
        for(int i = 0; i < st.length(); i++){
            dfs(base, s+1, newbase+st[i]);
        }
    }
};
