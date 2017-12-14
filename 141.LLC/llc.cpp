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
    /*
    使用两个指针walker和runner walker每次走一步
    runner每次走两步 如果成环 那么在某一次一定能碰到一起
    */
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* walker = head;
        ListNode* runner = head;
        while (runner->next && runner->next->next) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) return true;
        }
        return false;
    }
};