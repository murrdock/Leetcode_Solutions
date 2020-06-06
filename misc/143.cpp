class Solution {
public:
    ListNode* reverse(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *p = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
    ListNode* middle(ListNode* head){
        ListNode *f = head, *s = head;
        ListNode *p = NULL;
        while(f && f->next){
            p = s;
            s = s->next;
            f = f->next->next;
        }
        p->next = NULL;
        return s;
    }
    void reorderList(ListNode* head) {
        if(head != NULL && head->next != NULL){
            ListNode *f = head;
            ListNode *s = reverse(middle(head));
            ListNode *hd = NULL;
            head = hd;
            while(f && s){
                hd = f; f = f->next;
                hd->next = s; s = s->next;
                hd = hd->next;
                hd->next = f;
            }
            if(s) hd->next = s;
        }
    }
};
