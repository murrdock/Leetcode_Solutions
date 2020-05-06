#include<iostream>
#include<vector>

using namespace std;

/*
Explanation: First thing to notice is all subarrays from the index where min element is present
will be having minimum equal to the min. Now if you go from right to left, notice that for
any element till it's next minimum it's the minimum and you've already solved for it's next minimum.
Hence, at each index you can store sum of all subarrays starting from that index.
Eg. 2 3 2 1 2 4
    3 2 3 7 7 7     // array storing next minimum
    9 8 5 3 4 4     // array storing all subarrays min sum possible starting from that index.
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        long ans = 0;
        int N = 1000000007;
        // store the index of next minimum
        stack<int> s;
        vector<int> mind(A.size());
        for(int i = 0; i < A.size(); i++) {
            while(!s.empty() && A[i] < A[s.top()]) {
                mind[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {
            mind[s.top()] = A.size();
            s.pop();
        }
        vector<long> dp(A.size()+1,0);
        for(int i = A.size()-1; i >= 0; i--){
            dp[i] = A[i]*(mind[i]-i)+dp[mind[i]];
            dp[i] = dp[i]%N;
        }
        for(auto x : dp) {
            ans += x;
            ans = ans % N;
        }
        return ans;
    }
};
