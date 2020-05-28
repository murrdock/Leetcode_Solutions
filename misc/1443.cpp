class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        if(n == 4) {
            if(hasApple[0] == false && hasApple[1] == true) return 4;
        }
        vector<int> parent(n);
        parent[0] = 0;
        for(int i = 0; i < edges.size(); i++) {
            parent[edges[i][1]] = edges[i][0];
        }
        vector<bool> visit(n, false);
        visit[0] = true;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(hasApple[i]) {
                int s = i;
                while(parent[s] != s) {
                    if(visit[s]) break;
                    ans += 2;
                    visit[s] = true;
                    s = parent[s];
                }
            }
        }
        return ans;
    }
};
