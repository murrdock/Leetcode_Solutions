class Node{
private:
    vector<Node*> ve;
    bool set;
    bool is_end;
public:
    Node() {
        set = false;
        is_end = false;
    }
    void setNode() {
        this->set = true;
    }
    void setend() {
        this->is_end = true;
    }
    bool ifend() {
        return is_end;
    }
    bool ifset() {
        return set;
    }
    void make_parent(){
        if(ve.size()) return;
        ve.resize(26);
        for(int i = 0; i < 26; i++)
            ve[i] = new Node();
    }
    bool haschild() {
        return ve.size() > 0;
    }
    Node* findNode(int x){
        if(ve.size())
            return ve[x];
        return nullptr;
    }
};

class Trie {
    vector<Node*> root;
public:

    Trie() {
        root.resize(26);
        for(int i = 0; i < 26; i++)
            root[i] = new Node();
    }
    void insert(string s){
        if(s.length() == 0) return;
        Node* tmp = root[s[0]-'a'];
        int i = 0;
        for(i = 1; i < s.length(); i++){
            tmp->setNode();
            tmp->make_parent();
            tmp = tmp->findNode(s[i]-'a');
        }
        tmp->setNode();
        tmp->setend();
    }
    string traverse(string s){
        string ans = "";
        int i = 0;
        Node* tmp = root[s[i]-'a'];

        for(i = 1; i < s.length(); i++){

            if(!tmp->ifset()) return s;
            ans += s[i-1];
            if(tmp->ifend()) return ans;
            tmp = tmp->findNode(s[i]-'a');
            if(tmp == nullptr) return s;
        }

        return s;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie t;
        for(int i = 0; i < dict.size(); i++) {
            t.insert(dict[i]);
        }

        stringstream ss(sentence);
        string word;
        string res = "";
        while(ss >> word) {
            res  = res + t.traverse(word) + " ";
        }
        res.resize(res.length()-1);
        return res;
    }
};
