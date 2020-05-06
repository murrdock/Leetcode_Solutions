#include<bits/stdc++.h>

using namespace std;

/*
Explanation: If a rabbit says i.e arr[i] = 2, then two other rabbit which says 2 could be
the rabbit of same color(for minimum number of rabits). Hence total of 3 rabbit.
Look at this example for better understanding [0,0,1,1,1]
while the range is small we can use vector as a table(hash map).
*/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> m(1000);
        int ans = 0;
        for(auto x : answers) {
            if(m[x] == 0) {
                ans += x+1;
                m[x] = x;
            } else {
                m[x]--;
            }
        }
        return ans;
    }
};
