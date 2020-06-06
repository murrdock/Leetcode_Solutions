class Solution {
public:
    Node* inorder(Node* root, Node* next) {
        if(root == nullptr) return root;
        root->next = next;
        inorder(root->left, root->right);
        if(root->next) inorder(root->right, root->next->left);
        else inorder(root->right, root->next);
        return root;
    }
    Node* connect(Node* root) {
        return inorder(root, nullptr);
    }
};
