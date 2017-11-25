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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* head = sortedArrayToBST(nums, 0, nums.size() - 1);
        return head;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
        if (low > high) return NULL;
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, low, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, high);
        return node;
    }
};