class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size()/2;
        int n = matrix.size();

        for(int i = 0; i < m; i++){
            n = n-1;
            for(int j = 0; j + i< n; j++){

                swap(matrix[i][j + i], matrix[j+i][n]);

                swap(matrix[i][j + i], matrix[n][n-j]);

                swap(matrix[i][j + i], matrix[n-j][i]);

            }

        }
    }
};
