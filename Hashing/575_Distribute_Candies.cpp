#include<bits/stdc++.h>
/* Explanation:
Pay attention to the relation between the answer, total unique elements and array size.

For eg. if uniquie elements = 6(say u);
then for array size >= 12 girl can always get 6 different candies.
if array size == 10 then girl can get maximum 5 different
if array size == 8 then girl can get maximum 4 different
if array size == 6 then girl can get maximum 3 different
This reflects a clear relation i.e. n/2;
*/
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int u = 0;
        int m = *min_element(candies.begin(),candies.end());
        if(m < 0) {
            m = abs(m);
            for(auto& x : candies)
                x += m;
        }
        m = *max_element(candies.begin(),candies.end());
        vector<int> ve(m+1,0);
        for(auto &x : candies) {
            if(ve[x] == 0) u++;
            ve[x] = 1;
        }
        int n = candies.size();
        return min(n/2,u);
    }
};

int main(){
    int n; cin >> n;
    vector<int> ve(n);
    for(int i = 0; i < n; i++){
      cin >> ve[i];
    }
    Solution ob;
    cout << ob.distributeCandies(ve) << endl;
    return 0;
}
