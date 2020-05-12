
//Pay attention yourself. y is chosen as 2 in example where you can choose 1 as well.
//Imagine tree as a graph and from node x max 3 branches can be there. For y you've to choose on
//of those branches as selecting one node of the branch you can color all the nodes.

class Solution {
public:
    TreeNode* find(TreeNode* root,int x) {
        if(root) {
            if(root->val == x)
                return root;
            TreeNode* left = find(root->left, x);
            if(left != nullptr) return left;
            return find(root->right, x);
        }
        return nullptr;
    }
    int count(TreeNode* root) {
        if(root){
            return 1 + count(root->left) + count(root->right);
        }
        return 0;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* target = find(root, x);
        int l = count(target->left);
        int r = count(target->right);
        int p = n - l - r - 1;
        if(p > l+r+1) return true;
        else if(r > p+l+1) return true;
        else if(l > r+p+1) return true;
        else return false;
    }
};
