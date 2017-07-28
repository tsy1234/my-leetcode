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

    return res;
}());


