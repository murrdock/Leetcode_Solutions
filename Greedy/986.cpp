class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int pa = 0, pb = 0;
        vector<vector<int>> ans;
        while(pa < A.size() && pb < B.size()) {
            int sa = A[pa][0], ea = A[pa][1];
            int sb = B[pb][0], eb = B[pb][1];
            if(ea < sb) {
                pa++;
            } else if(eb < sa) {
                pb++;
            } else {
                int s = max(sa, sb), e = min(ea, eb);
                ans.push_back({s,e});
                if(ea < eb) pa++;
                else pb++;
            }
        }
        return ans;
    }
};
