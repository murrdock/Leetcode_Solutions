class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0, -1}, {0,1}};

    int n, m, curr, col;
    bool valid(int i, int j) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        curr = image[sr][sc];
        col = newColor;
        if(col == curr) return image;
        vector<vector<int>> nm = image;
        dfs(nm, sr, sc);
        return nm;
    }
    void dfs(vector<vector<int>>& image, int r, int c) {
        if(valid(r,c) and image[r][c] == curr) {
            image[r][c] = col;
            for(auto &x : dir)
                dfs(image, r+x[0], c+x[1]);
        }
    }
};
