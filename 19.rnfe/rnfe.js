function ListNode(val) {
    this.val = val;
    this.next = null;
}

var removeNthFromEnd = function (head, n) {
    var arr = [];
    var top = head;
    var newNode = null;
    while (top) {
        arr.push(top);
        top = top.next;
    }
    var length = arr.length;
    arr[length - n] = null;
    for (var i = length - 1;i >= 0;i--) {
        if (arr[i]) {
            var node = new ListNode(arr[i].val);
            node.next = newNode;
            newNode = node;
        }
    } 
    return newNode;
};
