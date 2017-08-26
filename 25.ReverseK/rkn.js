/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
// copy
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    var curr = head;
    var count = 0;
    while (curr && count < k) {
        curr = curr.next;
        count++;
    }

    if (count === k) {
        curr = reverseKGroup(curr, k);
        while (count-- > 0) {

        }
    }

    return head;
};