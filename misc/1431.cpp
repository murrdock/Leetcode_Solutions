class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *max_element(candies.begin(), candies.end());
        vector<bool> res(candies.size());
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= m) res[i] = true;
            else res[i] = false;
        }
        return res;
    }
};
