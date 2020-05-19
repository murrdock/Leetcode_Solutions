class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = -1e7, n = arr.size();
        int pmin = -1e7, pmax = -1e7;
        int cmin, cmax;
        for(int i=0; i<n; ++i){
             cmin = max(arr[i],  pmin+arr[i]);
             cmax = max( pmin, pmax+arr[i]);
                 res = max({res, cmin, cmax});
            pmin = cmin;
            pmax = cmax;
        }
        return res;
    }
};
