/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    var columns = twoDimen(9);
    var rows = twoDimen(9);
    var cube = twoDimen(9);
    for (var i = 0;i < 9;i++) {
        for (var j = 0;j < 9;j++) {
            var c = board[i][j];
            console.log(c);
            if (c !== '.') {
                var num = parseInt(c, 10);
                var k = parseInt(j / 3 + 1, 10) + parseInt((i / 3), 10) * 3;
                if (columns[i][num] || rows[j][num] || cube[k][num]) return false;
                columns[i][num] = rows[j][num] = cube[k][num] = 1;
            }
        }
    }
    return true;
};

var twoDimen = function (num) {
    var result = new Array(num);
    for (var i = 0;i < num;i++) {
        result[i] = new Array(num);
    }
    return result;
};

console.log(isValidSudoku([".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]));