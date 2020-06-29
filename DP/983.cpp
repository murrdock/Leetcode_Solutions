class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int x, y, z;
        vector<int> dp(days.size()+1, 0);
        dp[days.size()-1] = min(costs[0],min(costs[1],costs[2]));
        for(int i = days.size()-2; i>=0; i--){
            x = dp[i+1] + costs[0];
            int span = days[i]+6;
            int j = i;
            while(j < days.size()){
                if(days[j] <= span) j++;
                else break;
            }
            y = dp[j] + costs[1];
            span  = days[i] + 29;
            j = i;
            while(j < days.size()){
                if(days[j] <= span) j++;
                else break;
            }
            z = dp[j] + costs[2];
            dp[i] = min(x, min(y,z));
        }
        return dp[0];
    }
};
