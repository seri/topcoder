exports.countReachableIslands = function(a, L) {
    var n = a.length;
    var i;

    var start = a[0];
    a.sort(function (x, y) {
        return x - y;
    });
    var k = 0;
    for (i = 0; i < n; ++i) {
        if (a[i] == start) {
            k = i;
            break;
        }
    }

    var ret = 1;
    for (i = k; i > 0 && a[i] - L <= a[i - 1]; --i) {
        ret++;
    }
    for (i = k; i < (n - 1) && a[i] + L >= a[i + 1]; ++i) {
        ret++;
    }
    return ret;
};
