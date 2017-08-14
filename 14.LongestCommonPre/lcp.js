var longestCommonPrefix = function (strs) {
    var length = strs.length;
    var pre = '';
    var firstStr = strs[0] || '';
    var firstLength = firstStr.length;

    for (var i = 0;i < firstLength;i++) {
        var c = firstStr[i];

        for (var j = 1;j < length;j++) {
            if (strs[j][i] !== c) {
                break;
            }
        }

        if (j === length) {
            pre = pre + c;
        } else {
            break;
        }
    }

    return pre;
};

var test = ['tasiyu', 'taodandan', 'taoran'];
console.log(longestCommonPrefix(test));
