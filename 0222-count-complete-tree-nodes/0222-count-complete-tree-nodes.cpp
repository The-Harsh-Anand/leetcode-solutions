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
    int height(TreeNode* r) {
        if(!r) return 0;
        return 1+height(r->left);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh==rh) {
            return (1<<lh) + countNodes(root->right);
        } else {
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};