/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    var n = candidates.length
    candidates.sort(function (left, right) {return left - right})
    var result = []
    var combination = []
    backTracking(candidates, target, result, combination, 0)
    return result
};

var backTracking = function (candidates, target, result, combination, begin) {
    if (!target) {
        var temp = combination.slice()
        result.push(temp)
        return 
    }

    for (var i = begin;i < candidates.length && target >= candidates[i];i++) {
        console.log(i)
        combination.push(candidates[i])
        backTracking(candidates, target - candidates[i], result, combination, i)
        combination.pop()
    }
}

console.log(combinationSum([2, 3, 6, 7], 7))