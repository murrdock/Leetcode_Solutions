class Solution {
public:
    void flatten(TreeNode* root) {


        while(root) {
            if(root->left) {
                TreeNode *l = root->left;
                while(l->right) {
                    l = l->right;
                }
                l->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
