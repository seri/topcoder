#include <vector>
using namespace std;

double degreesTurned(vector<int> const &combo, int size, int start) {
    int n = combo.size(), pre = start, dir = 1;
    double inc = 360.0 / size, ret = n * (n + 1) * 180;
    for (int cur : combo) {
        int gap = (cur - pre) * dir;
        if (gap < 0) {
            gap = size + gap;
        }
        ret += inc * gap;
        pre = cur; dir *= (-1);
    }
    return ret;
}
