#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int days(vector<int> const &a, int lim) {
    int ret = 0, n = a.size(), x = 0;
    for (int i = 0; i != n; ++i) {
        x += a[i];
        if (x > 0) {
            ++ret;
            x = max(0, x - lim);
        }
    }
    ret += x / lim + (x % lim != 0);
    return ret;
}
