class Solution {
public:
    bool checkValidString(string s) {
        vector<int> T(s.length());
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*') T[i] = 1;
            else T[i] = s[i] == ')' ? 2 : 3;
        }
        stack<int> t;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                t.push(i);
            }
            else if(s[i] == ')' && !t.empty()){
                T[t.top()] = 0;
                T[i] = 0;
                t.pop();
            }
        }
        int adv = 0, left = 0, right = 0;
        for(int i = 0; i < T.size(); i++){
            if(T[i] == 1){
                if(left > 0) left--;
                else adv++;
            }
            else if(T[i] == 2){
                if(adv > 0) adv--;
                else return false;
            }
            else if(T[i] == 3){
                left++;
            }
            else{}
        }
        if(left > 0) return false;
        return true;
    }
};
