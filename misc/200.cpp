class Solution {
private:
    void span(vector<vector<char>>& grid, vector<vector<bool>>& T, int i, int j){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return;
        if(grid[i][j] == '0' || T[i][j]) return;
        else T[i][j] = true;
        span(grid,T, i-1, j);
        span(grid,T, i+1, j);
        span(grid,T, i, j-1);
        span(grid,T, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        if(!grid.size() || !grid[0].size()) return count;

        vector<vector<bool>> T(grid.size(), vector<bool> (grid[0].size(), false));

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && T[i][j] == false){
                    span(grid, T, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
