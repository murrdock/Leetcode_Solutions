class Solution {
public:
    vector<int> f;
    int findIntegers(int num) {
        f.resize(32);
        f[0] = 1;
        f[1] = 2;
        for(int i = 2; i < f.size(); i++)
            f[i] = f[i-1] + f[i-2];
        bitset<32> b(num);
        int i = 30, ans = 0;
        while(i >= 0) {
            if(b.test(i)) {
                ans += f[i];
                if(b.test(i+1)) {
                    ans--; break; //to not to include the number itself
                }
            }
            i--;
        }
        return ans + 1; // add 1 to include the number as well
    }

};
