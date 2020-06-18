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
            int r = distance(arr.begin(), upper_bound(arr.begin(), arr.end(), p[0]+p[1]-1));

            int q = query(0, l, r, 0, n-1);

            update(0, l, r, 0, n-1, q+p[1]);

            res.push_back(height[0]);
        }
        return res;
    }
};
