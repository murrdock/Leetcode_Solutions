class Solution {
public:
    int numSteps(int i, int j, int x, int y){
        return abs(x-i) + abs(y-j);
    }

    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int my_steps = numSteps(0,0, target[0], target[1]);
        for(int i = 0; i < ghosts.size(); i++){
            if(numSteps(ghosts[i][0], ghosts[i][1], target[0], target[1]) <= my_steps)
                return false;
        }
        return true;
    }
};
