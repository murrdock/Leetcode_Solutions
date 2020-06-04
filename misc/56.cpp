class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < intervals.size(); i++) {
            pq.push(make_pair(intervals[i][0], intervals[i][1]));
        }
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            if(!pq.empty() && pq.top().first <= p.second) {
                p.second = max(p.second, pq.top().second);
                pq.pop();
                pq.push(p);
            } else {
                ans.push_back({p.first, p.second});
            }
        }
        return ans;
    }
};
