/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
ListNode* merge(ListNode* l1, ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    if(l1->val <= l2->val){
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else{
        l2->next = merge(l1, l2->next);
        return l2;
    }
    return NULL;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;
        if(lists.size() == 1) return lists[0];

        queue<ListNode*> q;
        for(int i = 0; i < lists.size(); i++)
            q.push(lists[i]);

        ListNode *l1, *l2;

        while(!q.empty()){
            l1 = q.front();
            q.pop();
            l2 = q.empty() ? NULL : q.front();
            q.pop(); // even when q is empty in final case we're popping which make sure q to reach 0 even when final list is pushed onto it;
            q.push(merge(l1,l2));
            //cout << q.size() << " ";
        }
        return l1;
    }
};
