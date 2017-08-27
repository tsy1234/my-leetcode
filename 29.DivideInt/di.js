/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */

 // use bitwise operator to save much time
var divide = function(dividend, divisor) {
    var MAX_INT = Math.pow(2, 31) - 1, MIN_INT = -Math.pow(2, 31) - 1, l = Math.abs(dividend), r = Math.abs(divisor), result = 0
    while (l >= r) {
        var add = r 
        var mid = 1
        while ((add << 1) < l && (add << 1) > 0) {
            add <<= 1
            mid <<= 1
        }
        l -= add
        result += mid
    }

    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) result = -result
    if (result < MIN_INT || result > MAX_INT) return MAX_INT
    
    return result
};