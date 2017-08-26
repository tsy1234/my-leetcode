/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var length = nums.length
    if (length < 2) return nums
    var i = 1
    var index = nums[0]
    var result = 1
    while (i < length) {
        if (nums[i] == index) {
            i++
        } else {
            nums[result] = nums[i]
            result++
            index = nums[i]
        }
    }
    nums = nums.slice(0, result)
    return result
}

var better = function (nums) {
    var count = 0
    for (var i = 1;i < nums.length;i++)
        if (nums[i] === nums[i-1]) count++;
        else nums[i-count] = nums[i]
    
    return n - count
}

console.log(removeDuplicates([1, 1, 2, 3, 3, 3, 4]))