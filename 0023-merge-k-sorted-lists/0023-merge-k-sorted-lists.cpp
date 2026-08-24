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

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* temp = result;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = l1?l1:l2;
        return result->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(),i;
        if(n==0) return NULL;
        else if(n==1) return lists[0];
        ListNode* temp = lists[0];
        for(i=1;i<n;i++) {
            temp = mergeTwoLists(temp,lists[i]);
        }
        return temp;
    }
};