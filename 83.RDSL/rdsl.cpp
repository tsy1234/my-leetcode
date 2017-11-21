/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* back;
        while (cur) {
            back = cur->next;
            while (back && back->val == cur->val) {
                cur->next = back->next;
                back = cur->next;
            }
            cur = cur->next;
        }
        return head;
    }
};