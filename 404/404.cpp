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
private:
    int total;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        total = 0;
        recursive(root);
        return total;
    }

    void recursive(TreeNode* node) {
        if (!node) return;
        if (node->left && !node->left->left && !node->left->right) total += node->left->val;
        else recursive(node->left);
        recursive(node->right);
    }
};

// 返回值的方式
class another {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) {
            return root->left->val + sumOfLeftLeaves(root->right);
        } 
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
}