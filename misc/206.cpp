class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;

        ListNode *p = nullptr, *q = head;
        while(q) {
            ListNode *t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }
};
