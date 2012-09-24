#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getExitTime(vector<string> const &a) {
    int n = a.size();
    int is[n]; fill(is, is + n, 0); 
    bool ys[n]; fill(ys, ys + n, false);

    for (int ret = 0;; ++ret) {
        int j = 0, k = 0;
        for (; j != n; ++j) {
            if (ys[j]) {
                break;
            }
            if (is[j] < a[j].size()) {
                ys[j] = true;
                k = j;
            }
        }
        if (j == n) {
            j = k;
        }
        if (a[j][is[j]] == 'D') {
            return ret;
        }
        ++is[j];
        ys[j] = false;
    }
    return 0;
}
