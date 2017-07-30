var findTheLongest = function (str) {
    var length = str.length,
        max = 0;

    var allUnique = function (str, start, end) {
        var arr = [];

        for (var i = start; i < end; i++) {
            if (arr.indexOf(str[i]) > -1) return false;
            arr.push(str[i]);
        }

        return true;
    };

    for (var i = 0; i < length; i++) {
        for (var j = i + 1; j <= length; j++) {
            if (!allUnique(str, i, j))
                break;
            max = Math.max(max, j - i);
        }
    }

    return max;
};
console.log(findTheLongest('asdjjasdfasdjopejjfwoshishuiwalfnmzv'));
