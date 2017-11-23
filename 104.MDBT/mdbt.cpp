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
    int maxDepth(TreeNode* root) {
        return recur(root);
    }

    int recur(TreeNode* root) {
        if (NULL == root) return 0;
        int left = recur(root->left);
        int right = recur(root->right);
        return max(left, right) + 1;
    }

    int nice(TreeNode* root) {
        return NULL == root ? 0 : max(nice(root->left), nice(root->right)) + 1;
    }
};