/*global siyu*/


// time limit exceeded!!
var threeSum = function (nums) {
    var arr = sort(nums);
    var results = [];
    var length = arr.length;
    for (var i = 0; i < length && arr[i] <= 0; i++) {
        for (var j = i + 1; j < length; j++) {
            for (var k = j + 1; k < length; k++) {
                if (arr[i] + arr[j] + arr[k] === 0) {
                    var newA = [arr[i], arr[j], arr[k]];
                    if (!contain(newA, results)) {
                        results.push(newA);
                    }
                }
            }
        }
    }
    return results;
};
// time limit exceeded
var binaryThreeSum = function (nums) {
    var arr = sort(nums);
    var results = [];
    var length = arr.length;

    for (var i = 0; i < length; i++) {
        for (var j = i + 1; j < length; j++) {
            var index = siyu.binarySearch(arr.slice(j + 1), -arr[i] - arr[j]);
            if (index !== -1) {
                var newA = [arr[i], arr[j], -arr[i] - arr[j]];
                if (!contain(newA, results)) {
                    results.push(newA);
                }
            }
        }
    }

    return results;
};
// accepted
var threeSum3 = function (nums) {
    var arr = nums.sort();
    var length = arr.length;
    var results = [];

    for (var i = 0; i < length - 2; i++) {
        var front = i + 1;
        var end = length - 1;
        var target = -arr[i];

        while (front < end) {
            var add = arr[front] + arr[end];
            if (add < target) {
                front = front + 1;
            } else if (add > target) {
                end = end - 1;
            } else {
                var newA = [];
                newA.push(arr[i]);
                newA.push(arr[front]);
                newA.push(arr[end]);
                results.push(newA);
                while (front < end && arr[front] === newA[1]) {
                    front = front + 1;
                }
                while (front < end && arr[end] === newA[2]) {
                    end = end - 1;
                }
            }
        }

        while (i + 1 < length && arr[i + 1] === arr[i]) {
            i = i + 1;
        }
    }

    return results;
};

var contain = function (newA, allA) {
    for (var i = 0; i < allA.length; i++) {
        if (JSON.stringify(newA) == JSON.stringify(allA[i])) {
            return true;
        }
    }

    return false;
};

var sort = function (arr) {
    var tempArr = arr.slice();
    var length = tempArr.length;

    for (var i = 0; i < length; i++) {
        var min = tempArr[i];
        var index = i;

        for (var j = i + 1; j < length; j++) {
            if (tempArr[j] < min) {
                min = tempArr[j];
                index = j;
            }
        }

        if (index !== i) {
            tempArr[index] = tempArr[i];
            tempArr[i] = min;
        }
    }

    return tempArr;
};

var test = [12, 5, -12, 4, -11, 11, 2, 7, 2, -5, -14, -3, -3, 3, 2, -10, 9, -15, 2, 14, -3, -15, -3, -14, -1, -7, 11, -4, -11, 12, -15, -14, 2, 10, -2, -1, 6, 7, 13, -15, -13, 6, -10, -9, -14, 7, -12, 3, -1, 5, 2, 11, 6, 14, 12, -10, 14, 0, -7, 11, -10, -7, 4, -1, -12, -13, 13, 1, 9, 3, 1, 3, -5, 6, 9, -4, -2, 5, 14, 12, -5, -6, 1, 8, -15, -10, 5, -15, -2, 5, 3, 3, 13, -8, -13, 8, -5, 8, -6, 11, -12, 3, 0, -2, -6, -14, 2, 0, 6, 1, -11, 9, 2, -3, -6, 3, 3, -15, -5, -14, 5, 13, -4, -4, -10, -10, 11];
var test2 = [-1, 0, 1, 2, -1, -4];
var test3 = [-1, 0, 1, 2, -1, -4];
siyu.time.begin();
console.log(threeSum(test));
console.log(siyu.time.end());

siyu.time.begin();
console.log(binaryThreeSum(test));
console.log(siyu.time.end());

siyu.time.begin();
console.log(threeSum3(test));
console.log(siyu.time.end());
