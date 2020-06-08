class BSTIterator {
public:
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        s.push(root);
        arrange();
    }
    void arrange() {
        TreeNode *t = s.top(); s.pop();
        while(t) {
            s.push(t);
            t = t->left;
        }
    }
    /** @return the next smallest number */
    int next() {
        TreeNode *t = s.top(); s.pop();
        s.push(t->right);
        arrange();
        return t->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};
