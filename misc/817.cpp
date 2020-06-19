class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void make_set(int u) {
        parent[u] = u;
        size[u] = 1;
    }
    int find_set(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_set(parent[u]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int numComponents(ListNode* head, vector<int>& G) {
        if(head == nullptr) return 0;
        int m = 0;
        ListNode* curr = head;
        while(curr) {
            m = max(curr->val, m);
            curr = curr->next;
        }
        parent.assign(m+1, -1);

        size.resize(m+1);

        for(int i = 0; i < G.size(); i++) make_set(G[i]);

        curr = head;
        while(curr->next) {
            if(parent[curr->val] != -1 && parent[curr->next->val] != -1)
                union_set(curr->val, curr->next->val);
            curr = curr->next;
        }
        int ans = 0;
        for(int i = 0; i < G.size(); i++) {
            if(parent[G[i]] == G[i]) ans++;
        }
        return ans;
    }
};
