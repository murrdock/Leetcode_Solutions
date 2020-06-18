
class TreeNode1 {
  public :
  int l,r,h;
  TreeNode1 *left, *right;
  TreeNode1(int l, int r) {
    left = right = nullptr;
    this->l = l, this->r = l+r;
    h = r;
  }

  TreeNode1* insert(TreeNode1 *root, int l, int side,int &H) {
      TreeNode1* nroot = new TreeNode1(l, side);
      if(root == NULL) return nroot;
      int x = findHeight(root, l, l+side);
      nroot->h += x;
      H = max(H, nroot->h);
      int r = l+side;
      if(l >= root->l && r <= root->r) {
          nroot->left = root;
          nroot->right = root;
      }
      else if(l < root->l && r <= root->r) {
        nroot->left = root->left;
        nroot->right = root;
      } else if(l >= root->l && r > root->r) {
        nroot->left = root;
        nroot->right = root->right;
      } else {
        nroot->left = root->left;
        nroot->right = root->right;
      }
      return nroot;
  }
  int findHeight(TreeNode1* root, int l, int r) {
    if(root == nullptr) return 0;
    if(l >= r) return 0;
    if(l >= root->r) {
      return findHeight(root->right, l, r);
    } else if(r <= root->l) {
      return findHeight(root->left, l, r);
    }
    return max(root->h, max(findHeight(root->left, l, root->l), findHeight(root->right, root->r, r)));
  }
};



class Solution {
public:

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans(positions.size());
        ans[0] = positions[0][1];
        TreeNode1 *root = new TreeNode1(positions[0][0], positions[0][1]);
        int H = ans[0];
        for(int i = 1; i < positions.size(); i++) {
            root = root->insert(root, positions[i][0], positions[i][1], H);
            ans[i] = H;
        }
        return ans;
    }
};
