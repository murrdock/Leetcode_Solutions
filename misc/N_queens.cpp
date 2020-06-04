class Solution {
public:
    bool isValid(vector<int>& pos,int ind){
        for(int i=0;i<ind;i++){
            if(pos[i] == pos[ind])
                return false;
            if(abs(ind-i) == abs(pos[ind]-pos[i]))
                return false;
        }
        return true;
    }
    void AddPos(vector<vector<string>>& res,vector<int>&pos){
        vector<string> r;

        for(int i=0;i<pos.size();i++){
            string s = "";
            for(int j = 0;j<pos.size();j++){
                if(j == pos[i])
                    s+='Q';
                else s+='.';
            }
            r.push_back(s);
        }
        res.push_back(r);
    }
    void solve(vector<vector<string>>& res, vector<int>&pos,int ind){
        if(ind == pos.size())
            AddPos(res,pos);
        else{
            for(int i=0;i<pos.size();i++){
                pos[ind] = i;
                if(isValid(pos,ind)){
                    solve(res,pos,ind+1);
                }
                pos[ind] = INT_MIN;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n,INT_MIN);
        int ind = 0;
        solve(res,pos,ind);
        return res;
    }
};
