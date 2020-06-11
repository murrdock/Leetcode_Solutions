class Solution {
public:
    vector<int> countBits(int num) {

        int i,c=0,q=1;
        vector<int> dp(num+1);
        dp[0]=0;
        for(i=1;i<=num;i++)
        {
            if(i==q)
            {
                dp[i]=1;
                c=q;
                q*=2;
            }
            else
            {
                dp[i]=1+dp[i-c];
            }
        }
        return dp;
    }
};
