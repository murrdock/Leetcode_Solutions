class Solution {
private:
    pair<int,int> amount(TreeNode* node){
        if(node == NULL) return make_pair(0,0);

        int value;

        pair<int,int> left = amount(node->left);
        pair<int,int> right = amount(node->right);

        value = max(node->val + left.second + right.second, left.first + right.first);

        return make_pair(value, left.first + right.first);
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> res = amount(root);
        return max(res.first, res.second);
    }
};
