class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int t = k;
        for(int i = 0; i < num.length(); i++) {
            while(k > 0 && ans.length() && ans.back() > num[i]) {
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }

        ans.resize(num.length()-t);
        int i = 0;
        while(i < ans.length() && ans[i] == '0') {
            i++;
        }
        if(i == ans.length()) return "0";
        return ans.substr(i);
    }
};
