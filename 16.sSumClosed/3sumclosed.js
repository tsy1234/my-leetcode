// brutal accepted
var threeSumClosed = function (nums, target) {
    var distance = Infinity;
    var result;
    var length = nums.length;
    for (var i = 0;i < length;i++) {
        for (var j = i + 1;j < length;j++) {
            for (var k = j + 1;k < length;k++) {
                var add = nums[i] + nums[j] + nums[k];
                var dis = Math.abs(add - target);
                if (dis < distance) {
                    distance = dis;
                    result = add;
                }
            }
        }   
    }

    return result;
};

// faster
var threeSumClosed2 = function (nums, target) {
    var arr = nums.sort();
    var distance = Infinity;
    var result;
    var length = arr.length;

    for (var i = 0;i < length - 2;i++) {
        var first = i + 1;
        var end = length - 1;
        while (first < end) {
            var add = arr[i] + arr[first] + arr[end];
            var dis = Math.abs(add - target);

            if (dis === 0) {
                return target;
            }

            if (dis < distance) {
                distance = dis;
                result = add;
            }

            (add < target) ? first++ : end--;
        }
    }

    return result;
};

var result = threeSumClosed2([2, 4, 1, -3, 1], 5);
console.log(result);
