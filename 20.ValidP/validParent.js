var isValid = function (s) {
    var stack = [];
    var length = s.length;
    for (var i = 0;i < length;i++) {
        var c = s[i];
        if (i !== 0 && stack.length > 0 && stack[stack.length - 1] === obj[c]) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }
    return stack.length === 0;
};

var better = function (s) {
    var stack = [];
    for (var i = 0;i < s.length;i++) {
        if (s[i] === '(') stack.push(')');
        else if (s[i] === '[') stack.push(']');
        else if (s[i] === '{') stack.push('}');
        else if (stack.length === 0 || stack.pop() !== s[i]) return false;
    }
    return stack.length === 0;
};

var obj = {
	'}': '{',
	']': '[',
	')': '(',
};

console.log(isValid('[]{}()'));
