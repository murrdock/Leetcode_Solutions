class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        x.insert(x.begin(), {0,0,0});
        int i = 5;
        // move outwards
        while(i < x.size()){
            if(x[i] > x[i-2]) i++;
            else break;
        }
        // move on to the next edge
        i++;

        if(i < x.size() && x[i-1] + x[i-5] < x[i-3]) {
            if(x[i] >= x[i-2]) return true;
            else i++; // move on to the next edge
        } else if(i < x.size() && x[i] + x[i-4] >= x[i-2]) {
            return true;
        } else {
            i++;    // move on to the next edge
        }

        // move inwards
        while(i < x.size()){
            if(x[i] >= x[i-2]) return true;
            else i++;
        }
        return false;
    }
};
