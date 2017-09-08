/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    if (nums.length == 0) return 1
    nums = nums.sort(function (left, right) {return left - right})

    var first = nums[0]
    for (var i = 0;i < nums.length;i++) {
        var num = nums[i]
        if (num === first && num > 1) {
            return 1
        } else {
            if (num > 1 && num - 1 > nums[i - 1]) return (nums[i - 1] < 0) ? 1 : (nums[i - 1] + 1)
        }  
    }
    
    return nums[nums.length - 1] + 1
}

console.log(firstMissingPositive([3,3,1,4,0]))