class Solution {
public:
    unordered_map<int,int> m;

    int m_f = 0;

    int inorder(TreeNode* root){
        if(root == NULL) return 0;
        int left = inorder(root->left);
        int right = inorder(root->right);
        m[root->val + left + right]++;
        m_f = max(m[root->val+left+right], m_f);
        return left+right+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        inorder(root);
        vector<int> res;
        for(auto &it : m){
            if(it.second == m_f)
                res.push_back(it.first);
        }
        return res;
    }
};
