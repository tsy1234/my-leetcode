/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var mp = {};
    strs.forEach(function (ele) {
        var s = ele.split('').sort().join('');
        if (mp[s])
            mp[s].push(ele);
        else {
            mp[s] = [];
            mp[s].push(ele);
        }
    });

    var result = [];
    for (var key in mp) {
            result.push(mp[key]);
    }
    return result;
};

console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]));