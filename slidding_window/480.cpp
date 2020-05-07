#include <bits/stdc++.h>
using namespace std;
// Explanation : insert and delete in a BST. findmiddle element using inorder traversal
class Solution {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }
        if(root->val >= val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root->val == val) {
            if(root->left == NULL) return root->right;
            else if(root->right == NULL) return root->left;
            else {
                TreeNode* tmp = root->left;
                while(tmp->right) tmp = tmp->right;
                val = tmp->val;
                root->val = val;
                root->left = deleteNode(root->left, val);
            }
        } else if(root->val > val) {
            root->left = deleteNode(root->left, val);
        } else {
            root->right = deleteNode(root->right, val);
        }
        return root;
    }
    void inorder(TreeNode* root, int &k, double& ans) {

        if(root) {
            inorder(root->right, k, ans);
            if(k == 0) return;
            k--;
            if(k == 0) {
                ans = root->val;
                return;
            }
            inorder(root->left, k, ans);
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res(nums.size()-k+1);
        TreeNode* root = nullptr;
        for(int i = 0; i < k; i++) {
            root = insert(root, nums[i]);
        }
        for(int i = k; i <= nums.size(); i++) {
            if(k%2){
                int d = k/2+1;
                inorder(root, d, res[i-k]);
            } else {
                double t;
                int d = k/2+1;
                inorder(root, d, res[i-k]);
                d = k/2;
                inorder(root, d, t);
                res[i-k] = (res[i-k]+t)/2.0;
            }
            if(i == nums.size()) break;
            root = deleteNode(root, nums[i-k]);
            root = insert(root, nums[i]);
        }
        return res;
    }
};
