/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
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
        combination.push(candidates[i])
        backTracking(candidates, target - candidates[i], result, combination, i + 1)
        var pop = combination.pop()
        while (i < candidates.length)
            if (candidates[i + 1] === pop) i++
            else break
    }
}

console.log(combinationSum2([1, 1, 2, 5, 6, 7, 10], 8))