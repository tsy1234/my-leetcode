/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    var str = '1';
    for (var i = 1;i < n;i++) {
        var length = str.length;
        var currentChar = str[0];
        var res = '';
        var times = 1;
        for (var j = 1;j < length;j++) {
            if (str[j] == currentChar) {
                times++;
            } else {
                res = res + times + currentChar;
                times = 1;
                currentChar = str[j];
            }
        }
        res = res + times + currentChar;
        str = res;
    }
    return str;
};

console.log(countAndSay(5))