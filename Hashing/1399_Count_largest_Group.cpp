#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* Explanation
1 < n < 10^4. Hence the maximum sum of digits is 36.
Instead of using std::map<int,int> we can simply store inside a vector for better time.
*/
class Solution {
public:
    int countLargestGroup(int n) {
        int largest_size = 0;
        vector<int> m(40); // sum , count of elements in that group
        for(int i = 1; i <= n; i++) {
            int x = i;
            int sum = 0;
            while(x) {
                sum += x%10;
                x = x/10;
            }
            m[sum]++;
            largest_size = max(largest_size, m[sum]);
        }
        int ans = 0;
        for(auto &it : m) {
            if(it == largest_size) ans++;
        }
        return ans;
    }
};
