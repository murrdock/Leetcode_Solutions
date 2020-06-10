class NumArray {
public:
    vector<int> ve;
    int n;
    int build(vector<int>& nums, int l, int r, int i) {
        if(l == r) {
            return ve[i] = nums[l];
        } else {
            int m = (l+r)/2;
            return ve[i] = build(nums, l, m, 2*i+1) + build(nums, m+1, r, 2*i+2);
        }
    }

    void update(int l, int r, int pos, int val, int i) {
        if(l == r) {
            ve[i] = val;
            return;
        }
        int m = (l+r)/2;
        if(pos <= m) {
            update(l,m,pos,val,2*i+1);
        } else {
            update(m+1,r,pos,val,2*i+2);
        }
        ve[i] = ve[i*2+1] + ve[i*2+2];
    }

    int sum(int L, int R, int l, int r, int i) {
        if(l <= L && r >= R) return ve[i];
        int m = (L+R)/2;
        int ans = 0;
        if(l <= m) {
            ans += sum(L, m, l, r, 2*i+1);
        }
        if(r > m) {
            ans += sum(m+1, R, l, r, 2*i+2);
        }
        return ans;
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n) {
            ve.resize(n*4);

            build(nums, 0, n-1, 0);
        }
    }

    void update(int i, int val) {
        update(0,n-1,i,val,0);
    }

    int sumRange(int i, int j) {
        return sum(0, n-1, i, j, 0);
    }
};
