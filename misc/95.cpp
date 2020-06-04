class Solution {
public:
    vector<TreeNode*> generate(int l, int r) {
        vector<TreeNode*> res;
        if(l > r) {
            res.push_back(nullptr); return res;
        }

        for(int i = l; i <= r; i++) {
            vector<TreeNode*> left = generate(l, i-1);
            vector<TreeNode*> right = generate(i+1, r);
            for(auto L : left) {
                for(auto R : right) {
                    TreeNode *curr = new TreeNode(i);
                    curr->left = L;
                    curr->right = R;
                    res.push_back(curr);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generate(1, n);
    }
};
