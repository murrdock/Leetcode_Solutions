class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int m = 0;
        for(int i = 0; i < trips.size(); i++){
            m = max(m, trips[i][2]);
        }
        vector<int> hash(m+1, 0);
        for(int i = 0; i < trips.size(); i++){
            hash[trips[i][1]] += trips[i][0];
            hash[trips[i][2]] -= trips[i][0];
        }
        int curr = 0;
        for(int i = 0; i < hash.size(); i++){
            curr += hash[i];
            if(curr > capacity) return false;
        }
        return true;
    }

};
