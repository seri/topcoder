// The code below implements my approach. 
// It's not too elegant but it's quite simple to observe.
// For optimal solution: http://apps.topcoder.com/wiki/display/tc/SRM+519

int64 largestNumber(int64 x, int64 y) {
    if (y < 2) {
        return y;
    }
    int64 mid = 1;
    for (int64 temp = y; temp > 1; temp >>= 1) {
        mid <<= 1;
    }
    if (mid > x) {
        return (mid << 1) - 1;
    }
    return mid + largestNumber(x - mid, y - mid);
}
