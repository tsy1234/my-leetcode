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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* fake = new ListNode(-1);
        fake->next = head;
        ListNode* pre = fake, *cur = head;
        while (cur != NULL) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return fake->next;
    }

    ListNode* good(ListNode* head, int val) {
        if (head == NULL) return NULL;
        head->next = good(head->next, val);
        return head->val == val ? head->next : head;
    }
};