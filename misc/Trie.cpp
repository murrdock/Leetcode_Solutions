class TrieNode{
private:
    bool end;
    vector<TrieNode*> ve;
public:
    TrieNode() {
        end = false;
    }
    void allocate() {
        ve.assign(26, nullptr);
    }
    void checkPos(int x) {
        if(ve[x] == nullptr) ve[x] = new TrieNode();
    }
    bool isend() {
        return end;
    }
    void setend() {
        this->end = true;
    }
    TrieNode* getNode(int x) {
        return ve[x];
    }
    bool isNull() {
        return ve.size() == 0;
    }
};

class Trie {
public:
    TrieNode root;
    Trie() {}

    void insert(string word) {
        if(word.length() == 0) return;
        TrieNode *tmp = &root;
        for(int i = 0; i < word.length(); i++) {
            int pos = word[i]-'a';
            if(tmp->isNull()) tmp->allocate();
            tmp->checkPos(pos);
            tmp = tmp->getNode(pos);
        }
        tmp->setend();
    }

    bool search(string word) {
        TrieNode *tmp = &root;
        for(int i = 0; i < word.length(); i++) {
            int pos = word[i]-'a';
            if(tmp->isNull()) return false;
            tmp = tmp->getNode(pos);
            if(tmp == nullptr) return false;
        }
        return tmp->isend();

    }

    bool startsWith(string prefix) {
        TrieNode *tmp = &root;
        for(int i = 0; i < prefix.length(); i++) {
            int pos = prefix[i]-'a';
            if(tmp->isNull()) return false;
            tmp = tmp->getNode(pos);
            if(tmp == nullptr) return false;
        }
        return true;
    }
};
