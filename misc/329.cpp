class Solution {
public:
int distanceOf(vector<vector<int>>& A, vector<vector<int>>& L, int i, int j, int m, int n){
    if(m == -1 || n == -1 || m == L.size() || n == L[0].size()) return 0;

    if(A[m][n] <= A[i][j]) return 0;

    if(L[m][n] > 0) return L[m][n];

    vector<int> tmp;
    tmp.push_back(distanceOf(A,L,m,n,m-1,n));
    tmp.push_back(distanceOf(A,L,m,n,m+1,n));
    tmp.push_back(distanceOf(A,L,m,n,m,n-1));
    tmp.push_back(distanceOf(A,L,m,n,m,n+1));
    L[m][n] = 1 + *max_element(tmp.begin(),tmp.end());
    return L[m][n];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int i = matrix.size();    // i is number of rows
    if(i == 0) return 0;
    int j = matrix[0].size(); // j is number of columns
    vector<vector<int>> L(i, vector<int> (j) );
    for(int x = 0; x < i; x++){
        for(int y = 0; y < j; y++){
            vector<int> tmp;
            tmp.push_back(distanceOf(matrix,L,x,y,x-1,y));
            tmp.push_back(distanceOf(matrix,L,x,y,x+1,y));
            tmp.push_back(distanceOf(matrix,L,x,y,x,y-1));
            tmp.push_back(distanceOf(matrix,L,x,y,x,y+1));
            L[x][y] = 1 + *max_element(tmp.begin(),tmp.end());
        }
    }
    int m = 0;
    for(int x = 0; x < i; x++){
        for(int y = 0; y < j; y++){
            if(m < L[x][y]) m = L[x][y];
        }
    }
    return m;
}
};
