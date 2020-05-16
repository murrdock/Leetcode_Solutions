class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N < 10) return N;
        string s = to_string(N);
        bool state = false;
        for(int i = 0; i < s.length()-1; i++) {
            if(state) {
                s[i] = '9'; continue;
            }
            if(s[i] <= s[i+1]) {
                continue;
            } else { // when descend
              //handle the case like 332 answer has to be 299 not 329
                while(i-1 >= 0 && s[i] == s[i-1]) i--;
                s[i] = s[i]-1;
                state = true;
            }
        }
        if(state)
            s[s.length()-1] = '9';
        return stoi(s);
    }
};
