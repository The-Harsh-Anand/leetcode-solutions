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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0,curr=0;
        ListNode* n1=l1, *n2=l2, *sum=new ListNode(-1), *h=sum;
        while(n1 || n2) {
            if(n1) {
                curr+=n1->val;
                n1 = n1->next;
            }
            if(n2) {
                curr+=n2->val;
                n2 = n2->next;
            }
            curr+=carry;
            carry = curr/10;
            curr = curr%10;
            sum->next = new ListNode(curr);
            sum = sum->next;
            curr=0;
        }
        if(carry) {
            sum->next = new ListNode(carry);
        }
        return h->next;
    }
};