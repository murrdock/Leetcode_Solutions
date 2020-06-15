class node {
    public:
    int val;
    node *left, *right;
    node() {
        val = 0; left = right = nullptr;
    }
};
class Solution {
public:
    int res = 0;
    void insert(int v, node *head, node *a) {
        bitset<31> bit(v);
        node* b = head;
        for(int i = 30; i >= 0; i--) {
            if(bit.test(i)) {
                if(b->right == nullptr) b->right = new node();
                b = b->right;
                if(a->left) a = a->left;
                else a = a->right;
            } else {
                // sequence matters as you're performing while insertion
                if(b->left == nullptr) b->left = new node();
                b = b->left;
                // hence allocation is happened before if a and b goes into same direction
                if(a->right) a = a->right;
                else a = a->left;
            }
        }
        b->val = v;
        res = max(res, a->val ^ b->val);
    }
    int findMaximumXOR(vector<int>& nums) {
        node *root = new node();
        for(int i = 0; i < nums.size(); i++) {
            insert(nums[i], root, root);
        }
        return res;
    }
};
