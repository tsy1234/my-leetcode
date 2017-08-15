var siyu = (function() {
    var res = {};
    var clock;

    res.time = {
        begin: function() {
            clock = new Date();
        },
        end: function() {
            var now = new Date();
            return (now - clock) / 1000;
        }
    };

    res.binarySearch = function (arr, target) {
        var start = 0;
        var end = arr.length;

        while (start <= end) {
            var mid = parseInt((start + end) / 2, 10);
            if (arr[mid] === target) {
                return mid;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    };

    return res;
}());


