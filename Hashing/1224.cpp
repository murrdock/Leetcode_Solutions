#include <bits/stdc++.h>
using namespace std;

/*
Explanation:
For a prefix from 0-i, information we need is count of occurences of each element.
And to figure out if any prefix satisfies the condition we need the number of different
such values of count of occurences for all elements seen till now. Only if atmost 2
different values are there then there's a possibility for an answer.
We store in Hash_map(where size of map is number of different values of occurences)
<number of occurence, number of elements with this number of occurences>
*/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        if(nums.size() == 2) return nums.size();
        map<int,int> m; // number of unique values equal to size of map
        vector<int> ve(1 + *max_element(nums.begin(),nums.end()));
        int ans = 1;
        for(int i = 0; i < nums.size(); i++) {
            int x = ++ve[nums[i]];
            m[x]++;
            if(m.find(x-1) != m.end()) {
                if(m[x-1] == 1)
                    m.erase(x-1);
                else m[x-1]--;
            }
            if(m.size() == 1) {
                if(m.begin()->second == i+1 or m.begin()->first == i+1) ans = i+1;
            }
            if(m.size() == 2) {
                if(check(m)) {
                    ans = i+1;
                }
            }
        }
        return ans;
    }
    bool check(map<int,int> m) {
        pair<int,int> x,y;
        x = *m.begin();
        m.erase(m.begin());
        y = *m.begin();
        //cout << x.first << " " << x.second << " " << y.first << " " << y.second << endl;
        if(y.second == 1) {
            if(y.first == 1 or y.first == x.first + 1) return true;
        }
        if(x.second == 1) {
            if(x.first == 1 or x.first == y.first + 1) return true;
        }
        return false;
    }
};
