class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *f = new ListNode(INT_MIN);
        ListNode *tail = f;
        while(head) {
            if(tail->val <= head->val) {
                tail->next = head;
                head = head->next;
                tail = tail->next;
                tail->next = nullptr;
            } else {
                ListNode *t = f;
                while(t->next->val < head->val) {
                    t = t->next;
                }
                ListNode *tmp = head;
                head = head->next;
                tmp->next = t->next;
                t->next = tmp;
            }
        }
        return f->next;
    }
};
