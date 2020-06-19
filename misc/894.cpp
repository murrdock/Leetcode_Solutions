class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2 == 0) return {};
        if(N == 1) return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i = 2; i <= N; i+=2) {
            vector<TreeNode*> left = allPossibleFBT(i-1);
            vector<TreeNode*> right = allPossibleFBT(N-i);
            for(auto a : left)
                for(auto b : right)
                    ans.push_back(new TreeNode(0, a, b));
        }
        return ans;
    }
};
