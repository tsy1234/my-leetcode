/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    if (lists.length === 0) return [];
    while (lists.length > 1) {
        var first = lists.push();
        var second = lists.push();
        lists.pop(mergeTwoLists(first, second));
    }
    return lists;
};

/**
 * 
 * @param {ListNode[]} l1 
 * @param {ListNode} l2 
 * @return {ListNode}
 */
var mergeTwoLists = function (l1, l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    var list = new ListNode(0);
    var top = list;
    while (l1 && l2) {
        if (l1.val < l2.val) {
            list.next = l1;
            l1 = l1.next;
        } else {
            list.next = l2;
            l2 = l2.next;
        }
        list = list.next;
    }
    if (l1) list.next = l1;
    if (l2) list.next = l2;

    return top.next;
};
