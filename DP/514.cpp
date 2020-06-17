class Solution {
public:
    int n,m;
    string ring, key;
    // to make search for next occurence of character optimised
    vector<vector<int>> store;

    vector<vector<int>> dp;


    int findgreater(int x, int a){
        vector<int>&ve = store[a];
        auto it = lower_bound(ve.begin(),ve.end(),x);
        if(it == ve.end()) return (m-x)+ve[0];
        return *it-x;
    }

    int findsmaller(int x, int a){
        vector<int>& ve = store[a];
        if(ve[0] > x) return x + m-ve.back();
        auto it = lower_bound(ve.begin(),ve.end(),x);
        it = prev(it, 1);
        return x - *it;
    }

    int dfs(int i, int pos){
        if(pos == n) return 0;
        if(dp[i][pos] != -1) return dp[i][pos];
        if(ring[i] == key[pos]) return dp[i][pos] = 1 + dfs(i, pos+1);
        int x = i;
        int e = findgreater(x, key[pos]-'a');
        dp[i][pos] = e + dfs((i+e)%m, pos);
        x = i;
        e = findsmaller(x, key[pos]-'a');
        return dp[i][pos] = min(dp[i][pos], e + dfs((x+m-e)%m, pos));
    }
    int findRotateSteps(string ring, string key) {
        n = key.length();
        m = ring.length();
        store.assign(26, vector<int> ());
        for(int i = 0; i < ring.size(); i++){
            store[ring[i]-'a'].push_back(i);
        }
        for(auto &arr : store)
            sort(arr.begin(),arr.end());

        dp.assign(m, vector<int> (n,-1));
        this->ring = ring;
        this->key = key;
        dfs(0,0);
        return dp[0][0];
    }
};
