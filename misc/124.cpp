class Solution {
public:
    int ans = INT_MIN;

    int post(TreeNode* root) {
        if(root == nullptr) return 0;

        int l = post(root->left);
        int r = post(root->right);
        
        int m = max(root->val, max(root->val + l, max(root->val + r, root->val + l+ r)));
        ans = max(ans, m);
        return max(root->val, max(root->val + l, root->val+r));
    }

    int maxPathSum(TreeNode* root) {
        post(root);
        return ans;
    }
};
