class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> res(T.size(), 0);
        for(int i = 0; i < T.size(); i++){
            while(!s.empty() && T[i] > T[s.top()]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
