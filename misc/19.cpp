class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int t = 0;
        return back(head,n,t);
    }
    ListNode* back(ListNode* head, int n, int &t) {
        if(head == NULL) {
            return head;
        }
        head->next = back(head->next, n, t);
        t++;
        if(t == n) {
            return head->next;
        } else {
            return head;
        }
    }
};
