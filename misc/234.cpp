// Palindromic Linked List in O(n) time and O(1) space

class Solution {
public:
    bool check(ListNode** H, ListNode* head) {
        if(head->next == nullptr) {
            if(head->val == (*H)->val) {
                *H = (*H)->next;
                return true;
            } return false;
        }
        if(check(H, head->next)) {
            if(head->val == (*H)->val) {
                *H = (*H)->next;
                return true;
            }
        }
        return false;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        return check(&head, head);
    }
};
