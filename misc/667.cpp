class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int i = 0;
        bool turn = true;
        int l = 1, r = n;
        while(k) {
            k--;
            if(turn) {
                ans[i++] = l++;
                if(k) turn = !turn;
            } else {
                ans[i++] = r--;
                if(k) turn = !turn;
            }
        }
        while(i < n) {
            if(turn) ans[i++] = l++;
            else ans[i++] = r--;
        }
        return ans;
    }
};
