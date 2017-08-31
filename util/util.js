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
    /**
     * 
     * @param {Number[]} array
     * @param {Number} start
     * @param {Number} end - the end position of numbers
     */
    res.upSortPartOfArray = function (array, start, end) {
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

    return res;
}());


