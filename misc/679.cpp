// 24 Game
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> ve(nums.size());
        for(int i = 0; i < nums.size(); i++) ve[i] = nums[i];
        return solve(ve);
    }

    bool solve(vector<double> ve) {

        if(ve.size() == 0) return false;
        if(ve.size() == 1) return abs(ve[0]-24.0) < 1e-6;

        for(int i = 0; i < ve.size(); i++) {
            for(int j = 0; j < ve.size(); j++) {

                if(i == j) continue;

                vector<double> tmp;
                for(int k = 0; k < ve.size(); k++) if(k != i && k != j) tmp.push_back(ve[k]);

                double x = ve[i], y = ve[j], z;

                for(int k = 1; k < 5; k++) {
                    switch(k) {
                        case 1: z = x*y; break;
                        case 2: z = x+y; break;
                        case 3: z = x-y; break;
                        case 4: z = y != 0 ? x/y : 100000; break;
                    }
                    tmp.push_back(z);
                    if(solve(tmp)) return true;
                    tmp.pop_back();
                }

            }
        }
        return false;
    }
};
