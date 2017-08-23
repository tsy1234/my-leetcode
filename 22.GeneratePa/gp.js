/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var list = [];
    backtrack(list, '', n, 0);
    return list;
};

var backtrack = function (list, str, left, right) {
    if (left === 0 && right === 0) {
        console.log('tst');
        list.push(str);
        return ;
    }

    if (left > 0) backtrack(list, str + '(', left - 1, right + 1);
    if (right > 0) backtrack(list, str + ')', left, right - 1);
};
