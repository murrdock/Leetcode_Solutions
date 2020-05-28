class Solution {
public:
    int gcd(int a, int b) {
        if(a < b) return gcd(b, a);
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    vector<string> simplifiedFractions(int n) {
        if(n < 2) return {};
        vector<string> res;
        for(int i = 1; i < n; i++) {
            for(int j = i+1; j <= n; j++) {
                if(gcd(i,j) == 1) {
                    res.push_back(to_string(i)+"/"+to_string(j));
                }
            }
        }
        return res;
    }
};
