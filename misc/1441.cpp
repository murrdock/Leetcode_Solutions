class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int x = 0;
        vector<string> res;
        for(int i = 1; i <= n; i++) {
            res.push_back("Push");
            if(i == target[x]) {
                x++;
            } else {
                res.push_back("Pop");
            }
            if(x == target.size()) break;
        }
        return res;
    }
};
