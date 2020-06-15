class Solution {
public:
    Node* flatten(Node* head) {

        Node *t = head;
        while(head) {
            if(head->child != NULL) {
                Node *next = head->next;
                head->next = flatten(head->child);
                head->next->prev = head;
                head->child = nullptr;
                while(head->next) head = head->next;
                head->next = next;
                if(next) next->prev = head;
            }
            head = head->next;
        }
        return t;
    }
};
