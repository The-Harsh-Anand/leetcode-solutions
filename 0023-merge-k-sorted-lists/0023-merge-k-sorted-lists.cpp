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
    struct comp {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        for(auto& list:lists) {
            if(list) pq.push(list);
        }
        ListNode* result = new ListNode(-1);
        ListNode* temp=result;
        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            temp->next = curr;
            if(curr->next) pq.push(curr->next);
            temp = curr;
        }
        return result->next;
    }
};