// find different ways for left cross product with different ways for right using the operator at that position
class Solution {
public:
    inline int perform(int a, int b, char o) {
        if(o == '+') return a + b;
        else if(o == '-') return a-b;
        else return a * b;
    }

    vector<int> dfs(int s, int e, vector<int>& nums, vector<char>& op) {
        if(s == e) return vector<int>{nums[s]};
        vector<int> res;
        for(int i = s; i < e; i++) {
            vector<int> left = dfs(s, i, nums, op);
            vector<int> right = dfs(i+1, e, nums, op);
            for(int x = 0; x < left.size(); x++) {
                for(int y = 0; y < right.size(); y++)
                    res.push_back(perform(left[x],right[y],op[i]));
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string input) {
        int s = 0,r = 0;
        vector<int> nums;
        vector<char> op;
        for(r = 0; r < input.size(); r++){
            if(input[r] == '+' or input[r] == '-' or input[r] == '*') {
                nums.push_back(stoi(input.substr(s,r-s)));
                op.push_back(input[r]);
                s = r+1;
            }
        } nums.push_back(stoi(input.substr(s, r-s)));
        return dfs(0, nums.size()-1, nums, op);
    }
};
