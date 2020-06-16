class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>> ve(128);
        for(int i = 0; i < 128; i++) {
            ve[i].second = i;
        }
        for(int i = 0; i < s.length(); i++) {
            ve[s[i]].first++;
        }
        sort(ve.begin(),ve.end(),[](pair<int,int>& a, pair<int,int>& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        string ans;
        for(int i = 0; i < 128; i++) {
            if(ve[i].first) {
                ans += string(ve[i].first, ve[i].second);
            }
        }
        return ans;
    }
};
