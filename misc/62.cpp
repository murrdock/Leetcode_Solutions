class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = n-1;
        double ans = 1.0;
        for(int i = 1; i <= r; i++) {
            ans = ans * (N-r+i)/i;
        }
        return int(ans+0.03);
    }
};
