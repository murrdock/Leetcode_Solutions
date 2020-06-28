class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for(int n = A.size()-1; n >= 2; n--) {
            if(A[n] < A[n-1] + A[n-2]) return A[n]+A[n-1]+A[n-2];
        }
        return 0;
    }
};
