class Solution {
public:
    void helper(vector<int> &ans, int &ind, int N, int a, int d){
        if(N == 1){
            ans[ind++] = a;
        } else if( N == 2){
            ans[ind++] = a, ans[ind++] = a + d;
        } else {
            helper(ans, ind, (N+1)/2, a, 2 * d);
            helper(ans, ind, N/2, a+d, 2 * d);
        }
    }

    vector<int> beautifulArray(int N) {
        vector<int> ans(N);
        int ind = 0;
        helper(ans, ind, N, 1, 1);
        return ans;
    }
};
