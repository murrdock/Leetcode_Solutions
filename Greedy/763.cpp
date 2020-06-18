class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> la(26, -1);
        for(int i = 0; i < S.length(); i++) {
            la[S[i]-'a'] = i;
        }
        int l = 0, r =  0;
        vector<int> ans;
        for(int i = 0; i < S.length(); i++) {
            r = max(r, la[S[i]-'a']);
            if(r == i) {
                ans.push_back(r-l+1);
                l = r+1;
                r = 0;
            }
        }
        return ans;
    }
};
