// error
var roman = function (num) {
    var thousands = ['', 'M', 'MM', 'MMM'];
    var hundreds = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'];
    var tens = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'];
    var bits = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'];

    return thousands[parseInt(num / 1000, 10)] + hundreds[parseInt((num % 1000) / 100, 10)] + tens[parseInt((num % 100 % 100) / 10, 10)] + bits[
        parseInt(num % 10, 10)];
};

var romanTwo = function (num) {
    var renderNum = num;
    var weights = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    var tokens = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
    var romanStr = '';
    var start = 0;

    while (renderNum > 0) {
        for (var i = start;i < 13;i++) {
            if (renderNum >= weights[i]) {
                renderNum = renderNum - weights[i];
                romanStr = romanStr + tokens[i];
                break;
            }
            start = i + 1;
        }
    }

    return romanStr;
};

console.log(romanTwo(232));
