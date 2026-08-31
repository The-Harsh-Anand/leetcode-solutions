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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mn=INT_MAX, mx=-1;
        if(head->next==NULL || head->next->next==NULL) return {-1,-1};
        ListNode* curr = head->next,*prev=head,*nxt=curr->next;
        vector<int> dist;
        int ctr=2;
        while(nxt) {
            if((curr->val>prev->val && curr->val>nxt->val)||(curr->val<prev->val && curr->val<nxt->val)) {
                dist.push_back(ctr);
            }
            ctr++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        if(dist.size()<=1) return {-1,-1};
        for(int i=0;i<dist.size()-1;i++) {
            mn = min(mn,dist[i+1]-dist[i]);
        }
        mx = dist.back()-dist[0];
        return {mn,mx};
    }
};