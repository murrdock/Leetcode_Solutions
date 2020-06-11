class Solution {
public:
    int n;
    vector<int> T;
    void add(int i, int val) {
        while(i < n) {
            T[i] += val;
            i = i | (i+1);
        }
    }
    int sum(int r) {
        int ans = 0;
        while(r >= 0) {
            ans += T[r];
            r = (r & (r+1))-1;
        }
        return ans;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l);
    }
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        T.assign(n,0);
        vector<vector<int>> ve(n, vector<int>());
        for(int i = 0; i < nums.size(); i++) {
            ve[i] = vector<int>{nums[i],i};
        }
        sort(ve.begin(),ve.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++) {
            add(ve[i][1], 1);
            ans[ve[i][1]] = sum(ve[i][1], n-1);
        }
        return ans;
    }
};
