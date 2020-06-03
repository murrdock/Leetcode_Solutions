
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        if(head == nullptr) return head;
        int t = 1;
        ListNode *tm = head;
        while(t < k && tm->next) {
            tm = tm->next;
            t++;
        }
        if(t < k) return head;
        ListNode *tmp = reverseKGroup(tm->next, k);
        tm->next = NULL;
        ListNode *p = head, *q = head->next;
        p->next = tmp;
        while(q) {
            ListNode *t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }
};
