class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        ListNode* curr = head->next;
        if(curr != nullptr) {
            head->next = swapPairs(curr->next);
            curr->next = head;
            return curr;
        }
        return head;
    }
};
