class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }

    bool validate(TreeNode* root, TreeNode* minN, TreeNode* maxN) {
        if(root == nullptr) return true;

        if(minN != nullptr && root->val <= minN->val) return false;

        if(maxN != nullptr && root->val >= maxN->val) return false;

        return validate(root->left, minN, root) && validate(root->right, root, maxN);
    }
};
