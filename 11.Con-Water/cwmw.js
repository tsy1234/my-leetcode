/*global siyu*/
/**
 * time limit exceeded!!
 */
var maxAreaOne = function (height) {
    var arr = height.slice();
    var length = arr.length;
    var max = 0;

    var getContain = function (left, right) {
        var height = right - left;
        var side = Math.min(arr[left], arr[right]);
        return side * height;
    };

    for (var i = 0; i < length - 1; i++) {
        for (var j = i + 1; j < length; j++) {
            var contain = getContain(i, j);
            if (contain > max) {
                max = contain;
            }
        }
    }

    return max;
};

/**
 * accepted
*/
var maxAreaTwo = function (height) {
    var l = 0;
    var r = height.length - 1;
    var max = 0;

    while (l < r) {
        var left = height[l];
        var right = height[r];
        var side = Math.min(left, right);
        var tall = r - l;
        if (left > right) {
            r = r - 1;
        } else {
            l = l + 1;
        }
        max = Math.max(side * tall, max);
    }

    return max;
};

console.log(maxAreaTwo([1, 1]));
