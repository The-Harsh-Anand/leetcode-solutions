/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0,sum=0,ctr=1;
        countNode(root,ans,sum,ctr);
        return ans;
    }
    void countNode(TreeNode* r,int& ans, int& sum, int& ctr) {
        if(r==NULL) return;
        int s1=0,s2=0,c1=0,c2=0;
        if(r->left) {
            c1=1;
            countNode(r->left,ans,s1,c1);
        }
        if(r->right) {
            c2=1;
            countNode(r->right,ans,s2,c2);
        }
        sum+=(r->val+s1+s2);
        ctr+=(c1+c2);
        if(sum/ctr==r->val) ans++;
    }
};