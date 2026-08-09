/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode* curr=head, *nxt=head->next, *prev=dummy, *prv=NULL, *l=NULL;
        if(nxt==NULL || left==right) return curr;
        int ctr=1;
        while(ctr!=right && nxt) {
            if(l) {
                curr->next = prev;
            }
            if(ctr==left) {
                l = curr;
                prv = prev;
            }
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            ctr++;
        }
        l->next = curr->next;
        curr->next = prev;
        prv->next = curr;
        return dummy->next;
    }
};