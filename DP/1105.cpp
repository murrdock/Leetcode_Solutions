class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1);
        dp[n-1] = books[n-1][1];
        for(int i = n-2; i >= 0; i--){
            int span = books[i][0];
            int m = books[i][1];
            int j = i+1;
            dp[i] = m + dp[j];
            while(j < n){
                if(span + books[j][0] <= shelf_width){
                    span += books[j][0];
                    m = max(m, books[j][1]);
                    dp[i] = min(m + dp[j+1], dp[i]);
                    j++;
                } else {
                    break;
                }
            }
        }
        return dp[0];
    }
};
