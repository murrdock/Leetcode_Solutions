#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
Explanation : This problem can be reduced to longest common subsequence problem. Below code
is space optimized version of the same filling up the table in bottom up manner.
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<int> dp(B.size()+1,0);
        for(int i = 0; i < A.size(); i++) {
            int prev = dp[0];
            for(int j = 1; j < dp.size(); j++) {
                int tmp = dp[j];
                if(A[i] == B[j-1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j-1],tmp);
                }
                prev = tmp;
            }
        }
        return dp[B.size()];
    }
};

int main(){
    // take input A
    // take input B
    return 0;
}
