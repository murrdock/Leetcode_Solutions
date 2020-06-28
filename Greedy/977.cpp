class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int i = 0; i < A.size(); i++){
            A[i] = A[i]*A[i];
        }
        vector<int> N(A.size());
        int l = 0, r = A.size()-1;
        int x = A.size()-1;
        while(l <= r){
            if(A[l] > A[r]){
                N[x] = A[l];
                x--; l++;
            }
            else{
                N[x--] = A[r--];
            }
        }
        return N;
    }
};
