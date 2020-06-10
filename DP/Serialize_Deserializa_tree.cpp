class Codec {
public:
    // Encodes a tree to a single string.
    TreeNode* ans = NULL;

    string serialize(TreeNode* root) {
        ans = root;
        if(root == NULL) return "[]";
        deque<TreeNode*> dq;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* t = q.front();
            if(t == NULL){
                dq.push_back(NULL);
            }
            else{
                dq.push_back(t);
                q.push(t->left);
                q.push(t->right);
            }
            q.pop();
        }
        while(dq.back() == NULL)
            dq.pop_back();
        string s = "[";
        while(!dq.empty()){
            if(dq.front() == NULL)
                s = s + "null,";
            else
                s = s + to_string(dq.front()->val) + ",";
            dq.pop_front();
        }
        s[s.length()-1] = ']';
        //cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);
        data = data.substr(1,data.length()-2);

        string::iterator first = data.begin();
        while (first < data.end()) {
            TreeNode** pp = q.front();
            if (*first == 'n') {
                // *pp = nullptr;
                advance(first, 5);
            } else {
                string::iterator last = find(first, data.end(), ',');
                //cout << string(first,last) << " ";
                int val = stoi(string(first, last));
                *pp = new TreeNode(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first = next(last);
            }
            q.pop();
        }
        return root;
    }
};
