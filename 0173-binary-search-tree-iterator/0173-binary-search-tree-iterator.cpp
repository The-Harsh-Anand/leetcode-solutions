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
class BSTIterator {
public:
    TreeNode* temp;
    vector<int> inorder;
    int idx = 0,sz = 0;

    BSTIterator(TreeNode* root) {
        temp = root;
        inorder.push_back(INT_MAX);
        sz++;
        idx++;
        traverse(temp);
    }
    void traverse(TreeNode* temp) {
        if(!temp) return;
        traverse(temp->left);
        inorder.push_back(temp->val);
        sz++;
        traverse(temp->right);
    }

    int next() {
        return inorder[idx++];
    }
    
    bool hasNext() {
        return idx<sz;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */