class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k <= 3) return 1;
        int a = 1, b = 1;
        int x = 0;
        while(x < k) {
            x = a+b;
            a = b;
            b = x;
        }
        if(x == k) return 1;
        return 1 + findMinFibonacciNumbers(k-a);
    }
};
