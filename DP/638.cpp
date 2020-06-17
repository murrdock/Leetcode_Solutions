class Solution {
public:
    vector<int> prc;
    vector<vector<int>> offer;
    int n;
    unordered_map<string, int> map;
    int calculate(vector<int>& req){
        int ans = 0;
        for(int i = 0; i < req.size(); i++)
            ans += req[i] * prc[i];
        return ans;
    }
    int possible(vector<int>& aval, vector<int> need){
        int x = need.size();
        for(int i = 0; i < x; i++){
            need[i] = need[i] - aval[i];
            if(need[i] < 0) return -1;
        }
        return aval[x];
    }
    string convert(int x, vector<int>& need){
        string s = to_string(x) + "-";
        for(int i = 0; i < need.size(); i++){
            s += '0'+need[i];
        }
        return s;
    }
    vector<int> extraction(vector<int>& aval,vector<int>& need){
        vector<int> ans = need;
        for(int i = 0; i < ans.size(); i++){
            ans[i] -= aval[i];
        }
        return ans;
    }
    int dfs(int s, vector<int> needs){
        if(s == n) {
            return calculate(needs);
        }
        if(map.find(convert(s, needs)) != map.end()){
            return map[convert(s,needs)];
        }
        int ans = calculate(needs);
        for(int i = s; i < n; i++){
            int t = possible(offer[i], needs);
            if(t != -1){
                ans = min(ans, t + dfs(i, extraction(offer[i], needs)));
            }
        }
        return map[convert(s,needs)] = ans;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = special.size();
        prc = price;
        offer = special;
        return dfs(0, needs);
    }
};
