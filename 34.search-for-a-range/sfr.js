/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    var lo = 0;
    var hi = nums.length - 1;
    var result = [-1, -1];
    var index = -1;
    while (lo <= hi) {
        var mid = parseInt((hi + lo) / 2, 10);
        var num = nums[mid];
        if (num < target) lo = mid + 1;
        else if (num > target) hi = mid - 1;
        else {
            index = mid;
            break;
        }
    }
    if (index >= 0) {
        var left = index;
        while (nums[left - 1] == target) left--;
        var right = index;
        while (nums[right + 1] == target) right++;
        result = [left, right]; 
    }
    return result;
};

console.log(searchRange([1], 1))