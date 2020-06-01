class Solution {
public:
    #define lim(l,n) if(l == n) return 0

    inline bool ischar(char c) {
        return (c < '0' or c > '9') ;
    }
    int myAtoi(string s) {
        int n = s.length();
        int l = 0;

        while(l < n && s[l] == ' ') l++;

        lim(l,n);

        if(ischar(s[l]) && (s[l] != '+' && s[l] != '-')) return 0;

        bool sign = false;

        if(s[l] == '+') {
            sign = false;
            l++;
        } else if(s[l] == '-') {
            sign = true;
            l++;
        }

        lim(l,n);

        if(ischar(s[l])) return 0;

        while(l < n && s[l] == '0') l++;

        lim(l,n);

        if(ischar(s[l])) return 0;

        int r;
        for(r = l; r < n; r++) {
            if(ischar(s[r])) break;
        }
        string a = s.substr(l,r-l);

        a.resize(min(a.length(), to_string(INT_MAX).length()+1));

        long long ans = convert(a);

        long long int negl = INT_MIN, posl = INT_MAX;

        if(sign) {
            ans = -1LL*ans;
            if(ans < negl) return INT_MIN;
            return ans;
        }
        return ans > posl ? INT_MAX : ans;
    }
    long long convert(string s) {
        long long ans = 0;
        for(int i = 0; i < s.length(); i++) {
            ans = ans * 10 + (s[i]-'0');
        }
        return ans;
    }
};
