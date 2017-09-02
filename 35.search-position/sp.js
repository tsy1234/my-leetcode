/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var lo = 0;
    var hi = nums.length - 1;
    while (lo <= hi) {
        var mid = parseInt((lo + hi) / 2, 10);
        var num = nums[mid];
        if (num < target) lo = mid + 1;
        else if (num > target) hi = mid - 1;
        else return mid;
    }
    return low;
};