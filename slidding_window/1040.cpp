#include <bits/stdc++.h>
using namespace std;

/*
After sorting we have to consider consecutive sequence from each stones[i] and find that which requires minimum number of moves. Notice except for the case given in example 2 in all other cases the number of gaps is the number of moves because we can moves so that they directly fill in those empty gaps without breaking the rule.
For maximum moves we have to decide first move to be the minimum or maximum and we can make moves such that every gap between every number is used after that. In order to decide the first move A[1] - A[0] or A[N-1] - A[N-2] whichever gives maximum we'll pick that.
*/

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        int win = 0, ans = n;
        int l = 0, r = 0;
        while(r < n) {
            int x = stones[l];
            while(r < n && stones[r] < x+n) {
                r++;
            }
            win = r-l;
            if(win == n-1 and stones[r-1] == x+n-2){
                ans = min(ans, 2);
            } else {
                ans = min(ans, n - win);
            }
            l++;
        }
        int res = 0;
        for(int i = 1; i < n-2; i++) {
            res += stones[i+1]-stones[i]-1;
        }
        res += max(stones[1]-stones[0]-1, stones[n-1]-stones[n-2]-1);
        return {ans, res};
    }
};
