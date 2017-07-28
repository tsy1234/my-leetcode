var zigzag = function (s, row) {

    var length = s.length;
    var i = 0;
    var subs = [];
    var result = '';

    for (var j = 0;j < row;j++) {
        subs[j] = [];
    }

    while (i < length) {
        for (var down = 0;down < row && i < length;down++) {
            subs[down].push(s[i++]);
        }

        for (var up = row - 2;up > 0 && i < length;up--) {
            subs[up].push(s[i++]);
        }
    }

    for (j = 0;j < row;j++) {
        result += subs[j].join('');
    }

    return result;
};

console.log(zigzag('PAYPALISHIRING', 1));
