class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void helper(int s, int k, int val){
        if(k == 0) {
            if(val == 0) ans.push_back(res);
        } else {
            int limit = min(10-k, val);

            for(int x = s; x <= limit; x++){

                res.push_back(x);

                helper(x+1, k-1, val - x);

                res.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        helper(1, k, n);
        return ans;
    }
};
