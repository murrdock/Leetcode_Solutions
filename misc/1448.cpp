class Solution {
public:
    int cnt;
    void helper(TreeNode* root, int M) {
        if(root) {
            if(root->val >= M) {
                cnt++;
                M = root->val;
            }
            helper(root->left, M);
            helper(root->right, M);
        }
    }
    int goodNodes(TreeNode* root) {
        cnt = 0;
        helper(root, INT_MIN);
        return cnt;
    }
};
