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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto& list:lists) {
            ListNode* temp = list;
            while(temp) {
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* result = new ListNode(-1);
        ListNode* temp=result;
        while(!pq.empty()) {
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }
        return result->next;
    }
};