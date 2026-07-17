/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1 = p->val, v2 = q->val,v = root->val;
        if(v1==v) return p;
        if(v2==v) return q;
        if(v1<v && v2<v) return lowestCommonAncestor(root->left,p,q);
        else if(v1>v && v2>v) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};