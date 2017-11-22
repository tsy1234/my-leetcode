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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        TreeNode* left, *right;
        queue<TreeNode*> qLeft, qRight;
        qLeft.push(root->left);
        qRight.push(root->right);
        while (!qLeft.empty() && !qRight.empty()) {
            left = qLeft.front();
            qLeft.pop();
            right = qRight.front();
            qRight.pop();
            if (NULL == left && NULL == right) continue;
            if (NULL == left || NULL == right) return false;
            if (left->val != right->val) return false;
            qLeft.push(left->left);
            qLeft.push(left->right);
            qRight.push(right->right);
            qRight.push(right->left);
        }   
        return true;
    }
};