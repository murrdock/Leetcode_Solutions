class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() or !matrix[0].size()) return false;
        int r = 0, c = matrix[0].size()-1;
        int m = matrix.size();
        while(r < m && c >= 0) {
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] < target) {
                r++;
            } else {
                c--;
            }
        }
        return false;
    }
};
