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
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > res;
        queue<TreeNode*> q;
        if (NULL != root) q.push(root)
        while (!q.empty()) {
            vector<int> row;
            TreeNode* temp;
            cout << q.size() << endl;
            int size = q.size();
            for (int i = 0;i < size;i++) {
                temp = q.front();
                q.pop();
                if (NULL != temp) {
                    row.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                } 
            }
            if (!row.empty()) res.insert(res.begin(), 1, row);
        }
        return res;
    }

    void good(TreeNode* root) {
        DFS(root, 0);
        reutnr vector< vector<int> >(result.rbegin(), result.rend());
    }

    void DFS(TreeNode* root, int level) {
        if (NULL == root) return;
        if (level == result.size()) result.push_back(vector<int>());
        result[level].push_back(root->val);
        DFS(root->left, level + 1);
        DFS(root->right, level + 1);
    }

    vector< vector<int> > result;
};