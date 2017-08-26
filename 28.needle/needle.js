/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if (needle == '') return 0
    if (haystack == '') return -1;
    var hayLen = haystack.length
    var neLen = needle.length 
    var firstChar = needle[0]
    for (var i = 0; ;i++) {
        if (i === hayLen) return -1
        if (haystack[i] === firstChar) {
            for (var j = 0; ;j++) {
                if (i + j === hayLen) return -1;
                if (needle[j] !== haystack[i+j]) break;
                if (j === neLen - 1) return i
            }
        }
    }
}

console.log(strStr("mississippi", "a"))