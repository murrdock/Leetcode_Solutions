class TrieNode{
private:
    bool isEnd;
    TrieNode *links;

    TrieNode* allocate(){
        TrieNode *tmp = new TrieNode[26];
        return tmp;
    }
public:
    TrieNode(): isEnd(false), links(NULL){}

    void setLink(){
        links = this->allocate();
    }
    bool empty(){
        return (this->links==NULL);
    }
    void setEnd(){
        this->isEnd = true;
    }
    TrieNode* getLink(){
        return this->links;
    }
    bool isend(){
        return this->isEnd;
    }
};

class Trie {
public:
    TrieNode root;
    Trie() {
        root.setLink();
        root.setEnd();
    }
    void insert(string word) {
        TrieNode *a = &root;
        TrieNode *tmp = a->getLink();
        int n = word.length();
        for(int i = 0; i < n; i++){
            a = &tmp[word[i]-'a'];
            if(a->empty()){
                a->setLink();
                tmp = a->getLink();
            }
            else{
                tmp = a->getLink();
            }
        }
        a->setEnd();
    }
};


class Solution {
public:
    vector<string> ans;
    Trie tr;
    vector<vector<string>> dp;
    vector<string> wordBreak(string s, vector<string>& dict) {
        int n = s.length();
        // add words to trie
        for(int i = 0; i < dict.size(); i++) {
            tr.insert(dict[i]);
        }

        dp.assign(s.length()+1, vector<string>());

        dp[s.length()] = vector<string>{""};

        vector<bool> tp(n+1, false);
        tp[0] = true;
        for(int i = 0; i < n; i++) {
            if(tp[i]) {
                TrieNode *tmp = &tr.root;
                for(int j = i; j < n; j++) {
                    if(tmp->empty()) break;
                    tmp = &(tmp->getLink()[s[j]-'a']);
                    if(tmp->isend()) {
                        tp[j+1] = true;
                    }
                }
            }
        }
        if(tp[n] == false) return {};

        helper(0,s);

        vector<string>& ans = dp[0];

        for(auto &t : ans) t.pop_back();

        return ans;
    }

    void helper(int ind, string& s) {
        int n = s.length();

        if(ind == n) {
            return;
        }

        if(dp[ind].size() > 0) return;

        vector<string> ans;

        TrieNode *tmp = &tr.root;

        for(int j = ind; j < n; j++) {

            if(tmp->empty()) break;

            tmp = &(tmp->getLink()[s[j]-'a']);

            if(tmp->isend()) {
                helper(j+1, s);
                string t = s.substr(ind, j-ind+1);
                for(auto &ct : dp[j+1]) {
                    ans.push_back(t + " "+ ct);
                }
            }
        }
        dp[ind] = ans;
    }
};
