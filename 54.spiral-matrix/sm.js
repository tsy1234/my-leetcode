/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    var rowsMin = columnsMin = 0;
    var rows = matrix.length;

    if (rows == 0) return [];

    var columns = matrix[0].length;
    var total = rows * columns;
    var result = [];

    while (total > 0) {
        for (var i = columnsMin;i < columns;i++) {
            result.push(matrix[rowsMin][i]);
            total--;
        }

        if (total == 0) break;
        rowsMin++;

        for (var j = rowsMin;j < rows;j++) {
            result.push(matrix[j][columns - 1]);
            total--;
        }

        if (total == 0) break;
        columns--;

        for (var k = columns - 1;k >= columnsMin;k--) {
            result.push(matrix[rows - 1][k]);
            total--;
        }

        if (total == 0) break;
        rows--;

        for (var m = rows - 1;m >= rowsMin;m--) {
            result.push(matrix[m][columnsMin]);
            total--;
        }

        columnsMin++;
    }

    return result;
};
setTimeout(function() {
    console.log(spiralOrder([
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ]));
}, 3000);