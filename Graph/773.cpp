class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> s;
        string stage = "";
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++)
                stage += to_string(board[i][j]);
        }
        string target = "123450";
        vector<vector<int>> move = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<string> q;
        q.emplace(stage);
        int c = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string t = q.front();
                s.emplace(t);
                q.pop();
                if(t == target) return c;
                size_t f = t.find('0');
                for(auto p : move[f]){
                    swap(t[f], t[p]);
                    if(s.find(t) == s.end()){
                        q.emplace(t);
                    }
                    swap(t[f], t[p]);
                }
            }
            c++;
        }
        return -1;
    }
};
