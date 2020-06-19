class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int a = 0, b = 0;
        for(int i = 0; i < A.size(); i++){
            a = a + A[i];
        }
        for(int i = 0; i < B.size(); i++){
            b = b + B[i];
        }
        set<int> s(B.begin(),B.end());
        for(int i = 0; i < A.size(); i++){
            if(s.find(A[i]+(b-a)/2) != s.end())
                return {A[i], A[i]+(b-a)/2};
        }
        return {0,0};
    }
};
