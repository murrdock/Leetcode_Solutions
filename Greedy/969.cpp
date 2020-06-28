class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        int s = 0, n = A.size();
        while(s != n) {
            int val = n-s;
            if(A[n-s-1] == val) {
                s++; continue;
            }
            int p = distance(A.begin(),find(A.begin(),A.begin()+val, val));
            ans.push_back(p+1);
            ans.push_back(val);
            reverse(A.begin(),A.begin()+p+1);
            reverse(A.begin(),A.begin()+val);
        }
        return ans;
    }
};
