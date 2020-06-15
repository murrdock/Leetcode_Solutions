class Solution {
public:
    inline int count(int x) {
        return x * (x+1)/ 2 - x;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        vector<int> ve(n-1);
        for(int i = 1; i < n; i++) ve[i-1] = A[i] - A[i-1];
        int a;
        int ans = 0;
        for(int i = 0; i+1 < n; i++) {
            a = 1;
            while(i+2 < n && ve[i] == ve[i+1]) {i++; a++;}
            ans += count(a);
        }
        return ans;
    }
};
