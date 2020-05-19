class Solution {
public:
    using ll = long long int;
    ll gcd(ll a, ll b) {
        if(a < b) swap(a,b);
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    ll lcm(ll a, ll b) {
        return (a*b)/gcd(a,b);
    }
    ll calculate(ll n, ll a, ll b, ll c) {
        return n/a + n/b + n/c - n/lcm(a,b) - n/lcm(b,c) - n/lcm(a,c) + n/lcm(lcm(a,b),c);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l = 1, r = INT_MAX;
        int x = 0;
        while(l <= r) {
            ll m = (l+r)/2;
            ll d = calculate(m, a, b, c);
            if(d == n) {
                return max({m-m%a, m-m%b, m-m%c});
            } else if(d > n) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return -1;
    }
};
