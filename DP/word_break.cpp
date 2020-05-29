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
    bool wordBreak(string s, vector<string>& dict) {
        int n = s.length();
        Trie tr;
        for(int i = 0; i < dict.size(); i++) {
            tr.insert(dict[i]);
        }

        vector<int> dp(n+1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            if(dp[i]) {
                TrieNode *tmp = &tr.root;
                for(int j = i; j < n; j++) {
                    if(tmp->empty()) break;
                    tmp = &(tmp->getLink()[s[j]-'a']);
                    if(tmp->isend()) {
                        dp[j+1] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};
