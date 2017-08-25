/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if (!head) return null;
    var top = head;
    var sib = top.next;
    head = sib ? sib : head;
    var pre = null;
    while (top.next) {
        sib = top.next;
        var between = sib.next;
        sib.next = top;
        top.next = between;
        if (pre) pre.next = sib;
        pre = top;
        top = top.next;
    }
    return head;
};
// use recursion
var recursion = function (head) {
    if (!head || head.next) return head;
    var sib = head.next;
    head.next = recursion(sib.next);
    sib.next = head;
    return sib;
}