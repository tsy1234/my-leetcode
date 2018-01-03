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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL, *last = head;
        while (last != NULL) {
            ListNode* temp = last->next;
            last->next = pre;
            pre = last;
            last = temp;
        }
        return pre;
    }
    // pass the tail to the top by recursively
    ListNode* recur(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* res = recur(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
};