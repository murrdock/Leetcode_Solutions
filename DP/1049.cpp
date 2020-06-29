class Solution {
public:


    int lastStoneWeightII(vector<int>& stones) {
        //subset with given sum
        size_t n = stones.size();
        int total = 0;
        for(auto &x : stones) total += x;
        int sum = total/2;
        bitset<1501> m;
        m[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = sum; j - stones[i] >= 0; j--){
                if(m[j-stones[i]])
                    m[j] = 1;
            }
        }
        for(int j = sum; j >= 0; j--){
            if(m[j])
                return total - 2 * j;
        }
        return -1;
    }
};
