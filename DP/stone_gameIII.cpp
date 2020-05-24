// dfs with memoization
class Solution {
public:
    int n;
    vector<int> stones;
    vector<vector<int>> dp;
    int alice(int s) {
        if(s >= n) return 0;
        if(dp[s][0] != INT_MIN) return dp[s][0];
        int ans = INT_MIN;
        int sum = 0;
        for(int i = s; i < s+3 && i < n; i++) {
            sum += stones[i];
            ans = max(ans,sum + bob(i+1));
        }
        return dp[s][0] = ans;
    }
    int bob(int s) {
        if(s >= n) return 0;
        if(dp[s][1] != INT_MAX) return dp[s][1];
        int ans = INT_MAX;
        for(int i = s; i < s+3; i++) {
            ans = min(ans, alice(i+1));
        }
        return dp[s][1] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        stones = stoneValue;
        n = stones.size();
        dp.assign(n, vector<int> (2));
        for(int i = 0; i < n; i++) {
            dp[i][0] = INT_MIN;
            dp[i][1] = INT_MAX;
        }
        int sum = accumulate(stones.begin(),stones.end(),0);
        int a = alice(0);
        int b = sum - a;
        if(a == b) {
            return "Tie";
        } else if(a < b) {
            return "Bob";
        }
        else return "Alice";
    }
};

// bottom up dp
class Solution {
public:
    int n;
    vector<int> stones;
    vector<vector<int>> dp;
    string stoneGameIII(vector<int>& stoneValue) {
        stones = stoneValue;
        n = stones.size();
        stones.resize(n+3);
        dp.assign(n+3, vector<int> (2, 0));
        for(int i = 0; i < n; i++) {
            dp[i][0] = INT_MIN;
            dp[i][1] = INT_MAX;
        }
        for(int i = n-1; i >= 0; i--) {
            int sum = 0;
            for(int j = i; j < i+3; j++) {
                sum += stones[j];
                dp[i][0] = max(dp[i][0], sum + dp[j+1][1]);
                dp[i][1] = min(dp[i][1], dp[j+1][0]);
            }
        }
        int a = dp[0][0];
        int b = dp[0][1];
        if(a == b) {
            return "Tie";
        } else if(a < b) {
            return "Bob";
        }
        else return "Alice";
    }
};
