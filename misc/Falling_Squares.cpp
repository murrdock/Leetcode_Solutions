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


// using Segment Tree
class Solution {
public:
    vector<int> height, lazy;

    void push_down(int i) {
        if(lazy[i]) {
            lazy[i*2 + 1] = lazy[i*2 + 2] = lazy[i];
            height[i*2+1] = height[i*2+2] = lazy[i];
            lazy[i] = 0;
        }
    }
    void push_up(int i) {
        height[i] = max(height[2*i+1], height[2*i+2]);
    }
    int query(int i, int l, int r, int L, int R) {
        if(l <= L && r >= R) {
            return height[i];
        }
        push_down(i);
        int ans = 0;
        int mid = (L+R)/2;
        if(l < mid) {
            ans = max(ans, query(i*2+1, l, r, L, mid));
        }
        if(r > mid) {
            ans = max(ans, query(i*2+2, l, r, mid+1, R));
        }
        return ans;
    }
    void update(int i, int l, int r, int L, int R, int val) {
        if(l <= L && r >= R) {
            height[i] = val;
            lazy[i] = val;
            return;
        }
        push_down(i);
        int mid = (L+R)/2;
        if(l < mid) {
            update(2*i+1, l, r, L, mid, val);
        }
        if(r > mid) {
            update(2*i+2, l, r, mid+1, R, val);
        }
        push_up(i);
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> arr;
        for(int i = 0; i < positions.size(); i++) {
            arr.push_back(positions[i][0]);
            arr.push_back(positions[i][0] + positions[i][1]);
        }
        sort(arr.begin(), arr.end());
        auto it = unique(arr.begin(),arr.end());
        int n = distance(arr.begin(), it);
        arr.resize(n);
        height.resize(n << 2);
        lazy.resize(n << 2);

        vector<int> res;
        for(auto &p : positions) {
            int l = distance(arr.begin(), lower_bound(arr.begin(),arr.end(),p[0]));
            int r = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), p[0]+p[1]));

            int q = query(0, l, r, 0, n-1);
            update(0, l, r, 0, n-1, q+p[1]);

            res.push_back(height[0]);
        }
        return res;
    }
};
