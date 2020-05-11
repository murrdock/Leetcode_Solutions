// 24 Game

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ans;
    vector<int> op;
    vector<double> dig;
    double perform(double x, double y, int o) {
        switch(o) {
            case 1 : x = x*y; break;
            case 2 : x = y != 0 ? x/y : 100000; break;
            case 3 : x = x-y; break;
            case 4 : x = x+y; break;
        }
        return x;
    }
    // considering all possible evaluation of a 4 operand expression
    void evaluate3(double a, double b, double c, double d, int o1, int o2, int o3) {
        evaluate2(perform(a,b,o1),c,d,o2,o3);
        evaluate2(a,perform(b,c,o2),d,o1,o3);
        evaluate2(a,b,perform(c,d,o3),o1,o2);
    }
    void evaluate2(double a, double b, double c, int o1, int o2){
        evaluate(perform(a,b,o1),c,o2);
        evaluate(a,perform(b,c,o2),o1);
    }
    void evaluate(double a, double b, int o){
        double x = perform(a,b,o);
        if(abs(x-24) < 1e-6) ans = true; // this comparison is important as we consider till 6 decimal places in general
    }

    vector<int> opp = {1,2,3,4};
    bool judgePoint24(vector<int>& nums) {
        vector<bool> visit(nums.size(),false);

        ans = false;
        dfs(nums, visit, 4, true);

        return ans;
    }
    void dfs(vector<int>& nums, vector<bool>& visit, int n, bool turn) {
        if(n == 0) {
            evaluate3(dig[0],dig[1],dig[2],dig[3],op[0],op[1],op[2]);
        } else {
            if(turn) {
                for(int i = 0; i < nums.size(); i++){
                    if(!visit[i]){
                    visit[i] = true;
                    dig.push_back(nums[i]);
                    dfs(nums, visit, n-1, !turn);
                    dig.pop_back();
                    visit[i] = false;
                }
                }
            } else {
                for(int i = 0; i < opp.size(); i++) {
                    op.push_back(opp[i]);
                    dfs(nums, visit, n, !turn);
                    op.pop_back();
                }
            }
        }
    }
};
