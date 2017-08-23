/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

 function ListNode(val) {
     this.val = val;
     this.next = null;
 }
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    var list = new ListNode(0);
    var temp = list;
    var first = l1;
    var second = l2;
    while (first && second) {
        var node = null;
        if (first.val > second.val) {
            node = new ListNode(second.val);
            second = second.next;
        } else {
            node = new ListNode(first.val);
            first = first.next;
        }
        temp.next = node;
        temp = temp.next;
    } 
    
    temp.next = (first ? first : second);

    return list.next;
};
