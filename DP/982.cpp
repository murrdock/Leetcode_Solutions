class Solution {
public:
     int countTriplets(vector<int>& A) {
        vector<int> ump(1<<16, 0);
        int n = A.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ump[A[i]&A[j]]++;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int t = (~A[i]) & ((1 << 16)-1);
            for(int j=t; j; j=(j-1)&t) {
                ans += ump[j];
            }
            ans+=ump[0];
        }
        return ans;
    }
};
