var atoi = function (str) {
    var result = 0;
    var s = str.trim();
    var sArr = s.split('');
    var length = sArr.length;
    var numArr = [];
    var index = 0;
    var opArr = [];
    var INT_MAX = Math.pow(2, 31) - 1;
    var INT_MIN = -Math.pow(2, 31);
    // console.log(INT_MAX, INT_MIN);

    if (length === 0) {
        return result;
    }

    for (var i = 0;i < length;i++) {
        var a = sArr[i];
        var parse = parseInt(a, 10);
        if (parse >= 0) {
            var t = numArr[index];
            numArr[index] = (t) ? t + a : a; 
        } else {
            if (a === '+' || a === '-') {
                opArr.push(a);
                index = index + 1;
            } else {
                break;
            }
        }
    }

    if (numArr.length === 0) {
        return result;
    }

    // console.log(numArr);
    // console.log(opArr);

    for (var j = 1;j <= numArr.length;j++) {
        var pre = parseInt(numArr[j - 1], 10);

        if (j === 1 && !pre) {
            pre = 0;
        } else if (!pre) {
            return result;
        }

        var back = parseInt(numArr[j], 10);

        switch (opArr[j - 1]) {
            case '+':
                numArr[j] = pre + back;
                break;
            case '-':
                numArr[j] = pre - back;
                break;
        }

    }
    result = parseInt(numArr.pop(), 10);

    if (result > INT_MAX) {
        result = INT_MAX;
    } else if (result < INT_MIN) {
        result = INT_MIN;
    }

    return result;
};

var result = atoi('  -0012a42');
console.log(result);

