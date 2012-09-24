#include <vector>
using namespace std;

int bitCount(int n) {
    int ret = 0;
    while (n) {
        ++ret;
        n &= (n - 1);
    }
    return ret;
}

int find(int a, int b, int k) {
    vector<int> xs = {0, b};
    int start = -1, period = -1;
    for (int i = 2; start == -1 ; ++i) {
        int x = a * bitCount(xs[i - 1]) + b;
        for (int j = i - 1; j >= 0; --j) {
            if (x == xs[j]) {
                start = j;
                period = i - j;
            }
        }
        xs.push_back(x);
    }
    return k > start ? xs[(k - start) % period + start] : xs[k];
}
