//Transform the problem a bit by converting each column to a word
class Solution {
public:
    int n,m;
    bool compare(string &a, string &b) {
        for(int i = 0; i < a.length(); i++)
            if(a[i] > b[i])
                return false;
        return true;
    }
    vector<vector<int>> dp;

    // For top down depth first search
    int dfs(int prev, int s, vector<string>& arr, int l){
        if(s >= arr.size()) {
            return 0;
        }
        if(dp[prev][s] != -1) return dp[prev][s];
        if(compare(arr[prev],arr[s])) {
            return dp[prev][s] = min(dfs(s, s+1, arr, l+1), 1+dfs(prev, s+1, arr, l+1));
        }
        return dp[prev][s] = 1+dfs(prev, s+1,arr, l+1);
    }

    int minDeletionSize(vector<string>& A) {
        n = A.size(), m = A[0].size();
        dp.assign(102, vector<int> (102,0));
        vector<string> arr(m);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                arr[i] += A[j][i];
        }
        string s(n, 'a');
        arr.insert(arr.begin(),s);

        //bottom up dynamic programming
        for(int j = m; j > 0; j--) { // j is current
            for(int i = j-1; i >= 0; i--){ // i is prev
                if(compare(arr[i], arr[j])) {
                    dp[i][j] = min(1 + dp[i][j+1], dp[j][j+1]);
                } else {
                    dp[i][j] = 1 + dp[i][j+1];
                }
            }
        }
        return dp[0][1];
    }
};
