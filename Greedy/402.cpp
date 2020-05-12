//You can think of it as the problem like finding the smallet L digit number from the given array of digits same as you did for the maximum.
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0) return num;
        if(k == num.length()) return "0";
        string ans = "";
        int l = k;
        for(int i = 0; i < num.length(); i++) {
            while(k && ans.length() && ans.back() > num[i]) {
                k--;
                ans.pop_back();
            }
            ans += num[i];
        }
        ans.resize(num.length()-l);
        int x = 0;
        while(x < ans.length() && ans[x] == '0') x++;
        if(x == ans.length()) return "0";
        return ans.substr(x);
    }
};
