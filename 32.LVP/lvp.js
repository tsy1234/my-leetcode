/** call stack size exceeded
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    var nums = [];
    nums.range = [];
    var left = 0;
    var right = s.length - 1;
    nums.range[0] = left;
    nums.range[1] = right;
    if (right <= 0) return 0;
    isPa(s, nums, left, right);
    return nums.length > 0 ? Math.max.apply(Math, nums) : 0; 
};

/**
 * 
 * @param {String} str
 * @param {Number[]} array 
 * @param {Number} left 
 * @param {Number} right 
 */
var isPa = function (str, array, left, right) {
    if (left >= right || !(left >= array.range[0] && right <= array.range[1])) return ;
    var index = 0;
    while (left < right) {
        if (str[left] == ')') left++;
        else if (str[right] == '(') right--;
        else break;
    }
    var i;
    for (i = left;i <= right;i++) {
        if (str[i] == '(') index++;
        else if (str[i] == ')' && index > 0) index--;
        else break;
    }
    if (i > right && index == 0) {
        array.push(right - left + 1);
        array.range[0] = left;
        array.range[1] = right;
        console.log(right - left + 1, left, right);
    } else {
        isPa(str, array, left + 1, right);
        isPa(str, array, left, right - 1);
    }
};


var good = function (s) {
    var n = s.length;
    var stack = [];
    var longest = 0;
    for (var i = 0;i < n;i++) {
        if (s[i] == '(') stack.push(i);
        else if (s[i] == ')' && s[stack[stack.length - 1]] == '(') stack.pop();
        else stack.push(i);
    }
    if (stack.length == 0) longest = n;
    else {
        var a = n;
        while (stack.length > 0) {
            var b = stack.pop();
            longest = Math.max(longest, a - b -1);
            a = b;
        }
        longest = Math.max(longest, a);
    }
    return longest;
};

console.log(good('()()(()(('));


