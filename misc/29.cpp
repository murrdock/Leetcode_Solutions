class Solution {
public:
    int divide(int dividend, int divisor) {

        long long a = abs(static_cast<long long>(dividend));
        long long b = abs(static_cast<long long>(divisor));
        bool neg = (dividend < 0) != (divisor < 0);
        long long ans = 0;
        while(a >= b) {
            long long tmp = b;
            long long curr_bit = 1;
            while((tmp << 1) < a) {
                tmp = tmp << 1;
                curr_bit = curr_bit << 1;
            }
            ans += curr_bit;
            a = a - tmp;
        }

        if(neg) {
            ans = -ans;
        }
        if(ans > INT_MAX) {
            ans = INT_MAX;
        }
        return ans;
    }
};
