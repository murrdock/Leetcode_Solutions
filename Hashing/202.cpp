class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        while(true) {
            string x = to_string(n);
            n = 0;
            for(int i = 0; i < x.length(); i++) n += ((x[i]-'0')*(x[i]-'0'));
            if(n == 1) return true;
            if(s.count(n)) break;
            else s.insert(n);
        }
        return false;
    }
};
