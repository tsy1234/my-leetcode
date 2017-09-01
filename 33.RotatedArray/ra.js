/**竟然也accept了.. 我只是试一下..
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    var length = nums.length;
    for (var i = 0;i < length;i++) {
        if (nums[i] == target) return i;
    }
    return -1;
};

var good = function (nums, target) {
    var lo = 0;
    var hi = nums.length - 1;
    while (lo < hi) {
        var mid = parseInt((hi + lo) / 2, 10);
        var num = (nums[mid] < nums[0]) == (target < nums[0])
                ? nums[mid]
                : (target < nums[0]) ? -Infinity : Infinity;
        
        if (num < target) lo = mid + 1;
        else if (num > target) hi = mid - 1;
        else return mid;
    }
    return -1;
};

console.log(good([5, 6, 7, 8, 0, 1, 2, 3, 4], 2));