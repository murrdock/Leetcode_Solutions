class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == nullptr) return ans;
        bool state = false;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i < n; i++) {
                TreeNode *curr = q.front(); q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                tmp.push_back(curr->val);
            }
            if(state) {
                reverse(tmp.begin(),tmp.end());
            }
            ans.push_back(tmp);
            state = !state;
        }
        return ans;
    }
};
