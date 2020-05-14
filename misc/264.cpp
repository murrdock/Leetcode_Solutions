//using binary search to find the element for the i-th position similarity for n-th position

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n);
        arr[0] = 1;
        int x = 0, y = 0, z = 0;
        for(int i = 1; i < n; i++) {
             x = find(arr, 2, x, i);
             y = find(arr, 3, y, i);
             z = find(arr, 5, z, i);
             arr[i] = min(arr[x]*2, min(arr[y]*3, arr[z]*5));
        }
        return arr.back();
    }

    // return index
    int find(vector<int>& arr, long long x, int l, int r) {
        r = r-1;
        int ans = l;
        int last = arr[r];
        while(l <= r) {
            int m = (l+r)/2;
            if(x * arr[m] > last) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};
