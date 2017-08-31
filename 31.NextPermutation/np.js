/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
// hard
var nextPermutation = function(nums) {
    var length = nums.length;

    var isReverse = function (start) {
        if (length - start == 1) return true;
        for (var i = start;i < length - 1;i++) {
            if (nums[i] < nums[i + 1]) return false;
        }
        return true;
    };

    var sortPartOfArray = function (array, start, end) {
        for (var i = start;i < end;i++) {
            var min = array[i];
            var index = i;
            for (var j = i + 1;j <= end;j++) {
                if (array[j] < min) {
                    min = array[j];
                    index = j;
                }
            }
            if (index != i) {
                var test = array[i];
                array[i] = array[index];
                array[index] = test;
            }
        }
    };

    // 找到比但前位置元素大的第一个元素
    var findBigger = function (start, now) {
        for (var i = length - 1;i >= start;i--) {
            if (nums[i] > nums[now]) return i;
        }
        return -1;
    };
    // 交换两个元素的位置
    var exchange = function (pre, back) {
        var test = nums[pre];
        nums[pre] = nums[back];
        nums[back] = test;
    };

    var i;
    if (isReverse(0)) {
        nums.sort(function (a, b) {
            return a - b;
        });
    } else {
        for (i = length - 2;i >= 0;i--) {
            if (isReverse(i + 1)) {
                var big;
                if ((big = findBigger(i + 1, i)) > 0) {
                    exchange(i, big);
                    sortPartOfArray(nums, i + 1, length - 1);
                    break;
                }
            }
        }
    }

    if (i && i < 0) nums.sort(function (a, b) { 
        return a - b;       
    });
};

var better = function (nums) {
    var length = nums.length;
    if (length < 2) return;

    var index = length - 1;
    while (index > 0) {
        if (nums[index - 1] < nums[index]) break;
        index--;
    }

    if (index === 0) {
        // TODO reverse nums
    }
    else {
        var val = nums[index - 1];
        var j = n - 1;
        while (j >= index) {
            if (nums[j] > val)
                break;
            j--;
        }
        // swap and reverse
        return ;
    }
};

var test = [100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1];
nextPermutation(test);
console.log(test);