class Solution {
public:
    inline bool isprefix(string& s, string &a) {
        if(a.length() > s.length()) return false;

        for(int i = 0; i < a.length(); i++) {
            if(a[i] != s[i]) return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        vector<string> words;
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        for(int i = 0; i < words.size(); i++) {
            if(isprefix(words[i], searchWord)) return i+1;
        }
        return -1;
    }
};
