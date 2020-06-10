
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int l_r = 0, r_r = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                l_r++;
            else if(s[i] == ')'){
                if(l_r > 0)
                    l_r--;
                else
                    r_r++;
            }
        }
        set<string> out;

        validate(s, 0, l_r, r_r, 0, "", out);

        res.insert(res.begin(), out.begin(), out.end());
        return res;
    }
private:
    void validate(const string &s, int pos, int lr, int rr, int l, string curr, set<string> &res){
        if(pos == s.length()){
            if(lr == 0 && rr == 0 && l == 0)
                res.insert(curr);
            return;
        }
        else if(s[pos] != '(' && s[pos] != ')'){
            validate(s, pos+1, lr, rr, l, curr+s[pos], res);
        }
        else{
            if(s[pos] == '('){

                if(lr > 0)  validate(s, pos+1, lr-1, rr, l, curr, res);

                validate(s, pos+1, lr, rr, l+1, curr+s[pos], res);
            }
            if(s[pos] == ')'){

                if(l > 0)
                    validate(s, pos+1, lr, rr, l-1, curr+s[pos], res);

                if(rr > 0)
                    validate(s, pos+1, lr, rr-1, l, curr, res);
            }
        }
    }
};
