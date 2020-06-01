class Solution {
public:
    bool open(char c) {
        return c == '{' or c == '(' or c == '[';
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(open(s[i])) {
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false;
                if((st.top() == '(' && s[i] == ')') or (st.top() == '{' && s[i] == '}') or (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                } else return false;
            }
        }
        return st.empty();
    }
};
