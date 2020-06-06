class Solution {
public:
    TreeNode* tree(int l,int r, ListNode **head) {
        if(l > r) return nullptr;

        int mid = (l+r)/2;
        TreeNode *root = new TreeNode(0);
        root->left = tree(l, mid-1, head);
        root->val = (*head)->val;
        (*head) = (*head)->next;
        root->right = tree(mid+1, r, head);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while(curr) {
            n++;
            curr = curr->next;
        }
        return tree(1,n,&head);
    }
};
