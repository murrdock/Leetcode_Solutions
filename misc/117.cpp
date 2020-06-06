

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        Node *ln = connect(root->left);
        Node *rn = connect(root->right);
        if(ln && rn) ln->next = rn;

        while(ln && rn) {
            while(!ln->left && !ln->right && !(ln->next == rn) && ln->next) {
                ln = ln->next;
            }

            if(ln->left) ln = ln->left;
            else if(ln->right) ln = ln->right;
            else break;

            while(!rn->left && !rn->right && rn->next) {
                rn = rn->next;
            }

            if(rn->left) rn = rn->left;
            else if(rn->right) rn = rn->right;
            else break;

            Node* t = ln;
            while(t->next) t = t->next;
            t->next = rn;
        }
        return root;
    }
};
