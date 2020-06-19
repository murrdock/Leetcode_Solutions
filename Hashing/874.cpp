class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> s;
        for(auto &ve : obstacles){
            s.insert(to_string(ve[0])+"-"+to_string(ve[1]));
        }
        int x = 0, y = 0;
        int ans = 0;
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int d = 0;
        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -1){
                d = (4+d+1)%4;
            } else if(commands[i] == -2){
                d = (4+d-1)%4;
            } else {
                for(int a = 1; a <= commands[i]; a++){
                    if(s.find(to_string(x+dir[d][0])+"-"+to_string(y+dir[d][1])) == s.end()){
                        x = x + dir[d][0];
                        y = y + dir[d][1];
                        ans = max(ans, x * x + y * y);
                    } else break;
                }
            }
        }
        return ans;
    }
};
