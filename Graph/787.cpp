class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        vector<int> ve(n, 1e8);

        vector<vector<pair<int,int>>> adj(n);

        for(auto e : flights)  // directed graph
            adj[e[0]].push_back(make_pair(e[1], e[2]));

        ve[src] = 0;

        queue<int> q;

        q.push(src);

        // Breadth-First-Search
        while(!q.empty() && K+1) {
            int x = q.size();
            vector<int> dist(ve);
            for(int i = 0; i < x; i++) {
                int t = q.front(); q.pop();
                for(auto v : adj[t]) {
                    if(ve[t] + v.second < dist[v.first]) {
                        q.push(v.first);
                        dist[v.first] = ve[t] + v.second;
                    }

                }
            }
            ve = dist;
            K--;
        }
        return ve[dst] == 1e8 ? -1 : ve[dst];
    }
};
