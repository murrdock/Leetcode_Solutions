class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode *l = less, *b = big;
        while(head != nullptr) {
            if(head->val < x) {
                less->next = head;
                head = head->next;
                less = less->next;
                less->next = nullptr;
            }
            else {
                big->next = head;
                head = head->next;
                big = big->next;
                big->next = nullptr;
            }
        }
        less->next = b->next;
        return l->next;
    }
};
