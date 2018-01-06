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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* slow = head, *fast = head;
        // 通过这种方法定位到链表的中间位置 666
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 将后半段链表反转并通过head和slow检测前后两段是否值相同
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow != NULL) {
            if (slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        if (head->next == NULL) return head;
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
};