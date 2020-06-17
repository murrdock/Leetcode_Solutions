class Solution {
public:
    vector<int> prime;
    void fillPrimes(int n){
        for(int i = 2; i * i <= n; i++){
            if(prime[i] == i)
                for(int j = i+i; j <= n; j+=i)
                    prime[j] = i;
        }
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        prime.resize(n+1);
        iota(prime.begin(),prime.end(),0);
        fillPrimes(n);
        if(prime[n] == n) return n;
        int ans = 0;
        while(prime[n] != n) {
            ans += prime[n];
            n = n/prime[n];
        }
        return ans + prime[n];
    }
};
