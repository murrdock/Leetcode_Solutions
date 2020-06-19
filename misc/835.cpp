class Solution {
public:
    int m, n;
    int evaluate(vector<vector<int>>& A, vector<vector<int>>& B, int start_i, int start_j){
        int cnt = 0;
        int B_i = 0, B_j = 0;
        for(int i = 0; i < m; i++){
            B_i = i + start_i;
            if(B_i >= m) break;
            for(int j = 0; j < n; j++){
                B_j = j + start_j;
                if(B_j >= n) continue;
                if(A[i][j] == 1 && A[i][j] == B[B_i][B_j]) cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        m = A.size();
        n = A[0].size();
        int val = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                val = max(val, evaluate(A,B, i, j));
                val = max(val, evaluate(B,A, i, j));
            }
        }
        return val;
    }
};
