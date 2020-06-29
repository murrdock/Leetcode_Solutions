class Solution {
public:
    int maxRange(int i, int j, vector<int>& arr){
        int res = arr[i];
        for(int x = i; x <=j; x++){
            res = max(res, arr[x]);
        }
        return res;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int> (n));
        vector<vector<int> > M(n, vector<int> (n));
        for(int i = 0; i < n; i++){
            M[i][i] = arr[i];
        }
        for(int l = 1; l < n; l++){
            for(int i = 0; i < n-l; i++){
                M[i][i+l] = max(M[i][i+l-1], M[i+l][i+l]);
            }
        }


        for(int l = 1; l < n; l++){

            for(int i = 0; i < n-l; i++){
                int j = i+l;
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + M[i][k]*M[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
