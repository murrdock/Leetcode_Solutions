#include <bits/stdc++.h>

using namespace std;

/*
Explanation: use a sliding window with 'r'(right end) as loop variable. Suppose at index r
the window string has all three characters, then contract from left side memoizing the left
boundary. With the minimum window containing atleast 2 characters right end goes till the end
of string while left goes till the low. number of substrings will be the product.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a,b,c, ans = 0, l = 0;
        a = b = c = 0;
        for(int r = 0; r < s.length(); r++){
            if(s[r] == 'a') a++;
            else if(s[r] == 'b') b++;
            else c++;
            if(a && b && c) {
                int low = l;
                while(a && b && c) {
                    if(s[l] == 'a') a--;
                    else if(s[l] == 'b') b--;
                    else c--;
                    l++;
                }
                ans += (l-low)*(s.length()-r);
            }
        }
        return ans;
    }
};
