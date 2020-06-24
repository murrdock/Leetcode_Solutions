class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()) return false;
        int n = pushed.size();
        int i= 0, j = 0;
        stack<int> s;
        for(i; i < n; i++){
            s.push(pushed[i]);
            if(s.top() == popped[j]){
                while(!s.empty() && s.top() == popped[j]){
                    s.pop(); j++;
                }
            }
        }
        return s.empty();
    }
};
