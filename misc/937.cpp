class Solution {
public:
    bool digitLog(string& t) {
        if(t[t.length()-1] >= '0' && t[t.length()-1] <= '9')
            return true;
        return false;
    }
    struct comp{
        bool operator()(string& a, string & b) {
            int i = 0;
            while(a[i] != ' ') i++;
            string x = a.substr(i+1);
            i = 0;
            while(b[i] != ' ') i++;
            string y = b.substr(i+1);
            return (x == y) ? a <= b : x < y;
        }
    } comp;
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans(logs.size());
        int n = logs.size();
        int l = 0, d = 0;
        for(int i = 0; i < logs.size(); i++) {
            if(digitLog(logs[i])) d++;
        }
        int x = d;
        for(int i= 0; i < logs.size(); i++){
            if(digitLog(logs[i])){
                ans[n-d] = logs[i];
                d--;
            } else {
                ans[l++] = logs[i];
            }
        }
        sort(ans.begin(),ans.begin()+n-x, comp);
        return ans;
    }
};
