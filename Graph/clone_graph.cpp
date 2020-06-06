class Solution {
public:

    void dfs(Node* u, Node *nv, vector<Node*>& map, vector<bool>& visit){
        visit[u->val] = true;
        nv->neighbors.resize(u->neighbors.size());
        for(int i = 0; i < u->neighbors.size(); i++){
            nv->neighbors[i] = map[(u->neighbors[i])->val];
            if(!visit[(u->neighbors[i])->val])
                dfs(u->neighbors[i], nv->neighbors[i], map, visit);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        set<int> visit;
        int n = 0;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* tmp = q.front();
            q.pop();
            if(visit.find(tmp->val) == visit.end()){
                visit.insert(tmp->val);
                for(auto x : tmp->neighbors)
                    q.push(x);
            }
        }
        n = visit.size();
        vector<Node*> map(n+1);
        for(int i = 0; i < map.size(); i++){
            map[i] = new Node(i);
        }
        vector<bool> mark(n+1, false);
        dfs(node, map[node->val], map, mark);
        return map[node->val];

    }
};
