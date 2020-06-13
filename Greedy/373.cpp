class Solution {
public:


    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;

        for(auto x : nums1) {
            for(auto a : nums2) {
                if(pq.size() == k) {
                    if(x+a > pq.top().first) break;
                    pq.pop();
                    pq.push(make_pair(x+a, x));
                } else {
                    pq.push(make_pair(x+a, x));
                }
            }
        }
        while(!pq.empty()) {
            ans.push_back({pq.top().second, pq.top().first-pq.top().second});
            pq.pop();
        }
        return ans;

    }
};
