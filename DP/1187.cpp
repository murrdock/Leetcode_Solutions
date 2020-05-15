class Solution {
public:
    int INF = 2001;
    int n;
    vector<unordered_map<int,int>> dp;
    int search(vector<int>& arr, int k) {
        int ans = arr.size();
        int l = 0, r = arr.size()-1;
        while(l <= r) {
            int m = (l+r)/2;
            if(arr[m] > k) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }

    int dfs(int sid, int prev, vector<int>& arr, vector<int>& list) {
        if(sid == n) return 0;
        if(dp[sid].find(prev) != dp[sid].end()) return dp[sid][prev];
        int val1 = arr[sid] <= prev ? INF : dfs(sid+1, arr[sid], arr, list);
        int pos = search(list, prev);
        int val2 = pos == list.size() ? INF : 1 + dfs(sid+1, list[pos], arr, list);
        return dp[sid][prev] = min(val1, val2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int i = -1, j = 0;
        while(j < arr2.size()){
            arr2[++i] = arr2[j];
            while(j < arr2.size() && arr2[j] == arr2[i]) j++;
        }
        arr2.resize(i+1);
        n = arr1.size();
        dp.resize(n);
        int x = dfs(0,-1,arr1,arr2);
        return x < INF ? x : -1;
    }
};
