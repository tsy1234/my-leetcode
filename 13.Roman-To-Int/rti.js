var rti = function (roman) {
    var rInt = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };

    var length = roman.length;
    var result = 0;
    var pre = 0;
    var now = 0;

    for (var i = 0; i < length; i++) {
        var add = 0;
        now = rInt[roman[i]];
        add = (pre < now) ? now - 2 * pre : now;
        result = result + add;
        pre = now;
    }

    return result;
};

console.log(rti('VI'));
