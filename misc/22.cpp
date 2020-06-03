class Node {
    public :
    int l, r;
    string s;
    Node() {
        l = 0, r = 0;
        s = "";
    }
    Node(int x, int y, string t) {
        l = x, r = y;
        s = t;
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        Node t;
        queue<Node> q;
        q.push(t);
        while(!q.empty()) {
            Node x = q.front(); q.pop();
            if(x.l == n && x.r == n) {
                ans.push_back(x.s);
                continue;
            }
            if(x.l < n) {
                q.push(Node(x.l+1, x.r, x.s+"("));
            }
            if(x.l > x.r) {
                q.push(Node(x.l, x.r+1, x.s+")"));
            }
        }
        return ans;
    }
};
