// Bit manipulation
// Hashing
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

        unordered_map<unsigned int, int> word; // many words can have same integer representation
        for(int i = 0; i < words.size(); i++) {
            string &s = words[i];
            bitset<26> b;
            for(int j = 0; j < s.length(); j++)
                b.set(s[j]-'a');
            word[b.to_ulong()]++;
        }

        vector<int> ans(puzzles.size(),0);

        for(int i = 0; i < puzzles.size(); i++) {

            string p = puzzles[i];
            unsigned int x = 0;
            int pos = p[0]-'a';
            for(int j = 0; j < p.length(); j++)
                x += (1 << (p[j]-'a'));


            int t = 1 << pos;
            // all subset of integer representation of puzzle[i]
            for(int j = x; j; j = ((j-1)&x)){
                if(j & t)
                    ans[i] += word[j];
            }
        }
        return ans;
    }
};
