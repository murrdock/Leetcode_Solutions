class Solution {
public:

    int rectangleArea(vector<vector<int>>& rect) {
        set<int> s;
        for(int i = 0; i < rect.size(); i++) {
            s.insert(rect[i][1]);
            s.insert(rect[i][3]);
        }
        vector<int> lines;
        for(auto l : s)
            lines.push_back(l);
        long long int ans = 0;
        int N = 1e9+7;
        // sort at once so that no need to find interval using priority_queue againa nd again instead find it usings single traversal
        sort(rect.begin(), rect.end(), [](vector<int>& a, vector<int>& b){if(a[0] == b[0]) return a[2]>b[2]; return a[0] < b[0];});
        for(int l = 1; l < lines.size(); l++) {
            int ul = lines[l];
            int bl = lines[l-1];
            int left = 0, right = 0;
            for(int i = 0; i < rect.size(); i++) {
                if(rect[i][1] <= bl && rect[i][3] >= ul) {
                    if(rect[i][0] <= right) {
                        right = max(right, rect[i][2]);
                        left = min(left, rect[i][0]);
                    } else {
                        ans += (long long int)(right-left)*(ul-bl);
                        ans = ans % N;
                        left = rect[i][0];
                        right = rect[i][2];
                    }
                }
            }
            ans += (long long int)(right-left)*(ul-bl);
            ans = ans%N;
        }
        return ans;
    }
};
