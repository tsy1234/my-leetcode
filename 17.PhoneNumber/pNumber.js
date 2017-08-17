var letterCombinations = function (digits) {
    var maps = ['0', '1', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    var results = [''];
    for (var i = 0;i < digits.length;i++) { 
        var length = results.length;
        var single = maps[parseInt(digits[i], 10)];
        var j = 0;
        while (j < length) {
            for (var k = 0;k < single.length;k++) {
                results.push(results[0] + single[k]);
            }
            j++;
            results.shift();
        }
    }

    if (results[0] === '') {
        return [];
    } else {
        return results;
    }
};

var result = letterCombinations('234');
console.log(result);
