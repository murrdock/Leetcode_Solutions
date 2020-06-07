class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB) return nullptr;
        ListNode *p = headA, *q = headB;
        int end = 0;
        while(p && q) {
            if(p == q) return p;
            if(p->next == nullptr) {
                if(end && p->val != end) return NULL;
                end = p->val;
                p = headB;
                q = q->next;
                continue;
            }
            if(q->next == nullptr) {
                if(end && q->val != end) return nullptr;
                end = q->val;
                q = headA;
                p = p->next;
                continue;
            }
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};
