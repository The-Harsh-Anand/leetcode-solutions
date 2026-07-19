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
    int count=0;
    int helper(TreeNode* r) {
        if(r==NULL) return 0;
        int lMax = helper(r->left);
        int rMax = helper(r->right);
        if(r->val>=max(lMax,rMax)) count++;
        return max(r->val,max(lMax,rMax));
    }
    int countDominantNodes(TreeNode* root) {
        helper(root);
        return count;
    }
};