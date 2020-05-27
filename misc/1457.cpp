class Solution {
public:
    int ans = 0;
    inline bool check(vector<int>& ve) {
        int x = 0;
        for(int a : ve) x += a%2;
        if(x > 1) return false;
        return true;
    }
    void helper(TreeNode* root, vector<int>& ve) {
        if(root) {
            ve[root->val]++;
            if(root->left == NULL && root->right == NULL) { // leaf node
                if(check(ve)) ans++;
            }
            helper(root->left, ve);
            helper(root->right, ve);
            ve[root->val]--;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> ve(10, 0);
        helper(root, ve);
        return ans;
    }
};
