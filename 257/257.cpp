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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) return res;
        string s = "";
        recur(res, s, root);
        return res;   
    }

    void recur(vector<string>& res, string s, TreeNode* node) {
        if (!root->left && !root->right) {
            res.push_back(s);
        }

        if (root->left) recur(res, s + "->" + to_string(root->left->val), root->left);
        if (root->right) recur(res, s + "->" + to_string(root->right->val), root->right);
    }
};