#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getMinimum(vector<int> a) {
    sort(a.begin(), a.end());
    int n = a.size();
    if (a[n - 1] == 0) {
        return 0;
    }
    for (int ret = 1; ret <= n; ++ret) {
        int pos = n - ret;
        if (a[pos] > ret) {
            if (pos == 0 || a[pos - 1] <= ret) {
                return ret;
            }
        }
    }
    return -1;
}
