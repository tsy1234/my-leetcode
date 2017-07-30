/**
 * first solution
*/
var reverseInt = function (x) {
    var max = Math.pow(2, 31) - 1; // define overflow
    var index = 1;

    if (x < 0) {
        index = -1;
        x = Math.abs(x);
    }

    var str = x + '';
    str = str.split('').reverse().join('');
    
    var result = parseInt(str, 10);
    result = (result > max) ? 0 : index * result;
    
    return result;
};

console.log(reverseInt(10100));
