var pn = function (num) {
    if (num < 0 || (num !== 0 && num % 10 === 0)) {
        return false;
    }

    var rev = 0;

    while (num > rev) {
        rev = rev * 10 + num % 10;
        num = parseInt(num / 10, 10);
    }
    
    return ((num === rev) || (num === parseInt(rev / 10, 10)));
};

console.log(pn(23332));
