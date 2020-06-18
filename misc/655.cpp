class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int width(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + 2 * max(width(root->left), width(root->right));
    }
    void fill(TreeNode* root, vector<vector<string>>& res, int i, int j, int n){
        if(root == NULL) return;
        res[i][j] = to_string(root->val);
        fill(root->left, res, i+1, j-n/2-1, n/2);
        fill(root->right, res, i+1, j + n/2 +1, n/2);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int m = height(root);
        int n = width(root);

        vector<vector<string>> res(m, vector<string> (n, ""));
        fill(root, res, 0, n/2, n/2);
        return res;
    }
};
