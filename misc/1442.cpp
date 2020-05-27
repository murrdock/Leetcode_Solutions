class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,int> sum; // value , sum of indices with that value
        unordered_map<int,int> freq; // value , freq of that value
        int ans = 0;
        int cur = 0;
        freq[0] = 1;
        for(int i = 0; i < arr.size(); i++) {
            cur ^= arr[i];
            ans += freq[cur]*i-sum[cur];
            freq[cur]++;
            sum[cur]+=i+1;
        }
        return ans;
    }
};
