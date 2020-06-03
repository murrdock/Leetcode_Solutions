class Solution {
public:
    int longestValidParentheses(string s) {
        if(s == "") return 0;
        vector<int> ve(s.length());
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                if(st.empty()) {
                    ve[i] = 1;
                } else {
                    ve[st.top()] = 0;
                    ve[i] = 0;
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            ve[st.top()] = 1; st.pop();
        }
        int ans = 0;
        int l = 0;
        for(int r = 0; r < ve.size(); r++) {
            if(ve[l] == 1) l++;
            if(ve[r] == 0) {
                ans = max(ans, r-l+1);
            } else {
                l = r;
            }
        }
        return ans;
    }
};
