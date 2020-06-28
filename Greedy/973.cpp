class Solution {
public:
    using lo = long long int;
    using pi = pair<lo, lo>;
    #define X first
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pi> pq;
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            pi p = make_pair(x*x + y*y, i);
            if(pq.size() == K) {
                if(p.X < pq.top().X) {
                    pq.pop();
                    pq.push(p);
                }
            } else {
                pq.push(p);
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
