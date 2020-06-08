class Solution {
public:
    using llu = long long int;
    string fractionToDecimal(int nume, int deno) {
        if(nume == 0) return "0";

        bool neg = (nume < 0) ^ (deno < 0);

        llu num = abs(nume);
        llu den = abs(deno);
        llu dec = num/den;

        string ans = to_string(dec);

        map<llu,int> s;

        llu r = num%den;

        if(r) ans.push_back('.');

        while(r && s.find(r) == s.end()) {
            s[r] = ans.length();
            num = r * 10;
            while(num < den) {
                ans.push_back('0');
                num = num * 10;
            }
            ans += to_string(num/den);
            r = num%den;
        }

        if(r) {
            ans.insert(s[r], 1, '(');
            ans.push_back(')');
        }

        if(neg) ans.insert(ans.begin(),'-');

        return ans;
    }
};
