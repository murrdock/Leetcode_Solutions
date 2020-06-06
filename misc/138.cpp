class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        if(head == NULL) return head;
        Node* tmp = head;
        while(tmp != NULL){
            Node *tmp2 = new Node(tmp->val, NULL, NULL);
            m[tmp] = tmp2;
            tmp = tmp->next;
        }
        tmp = head;
        Node *copy = m[tmp];
        while(tmp != NULL){
            Node *y = m[tmp];
            y->next = m[tmp->next];
            y->random = m[tmp->random];
            tmp = tmp->next;
        }
        return copy;
    }
};
