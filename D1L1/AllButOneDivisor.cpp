#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_INT = 1 << 30;

int gcd(int p, int q) {
    if (q == 0) {
        return p;
    }
    return gcd(q, p % q);
}

int lcm(int p, int q) {
    return (p * q) / gcd(p, q);
}

int getMinimum(vector<int> a) {
    int n = a.size(), ret = MAX_INT;
    for (int k = 0; k != n; ++k) {
        int x = 1;
        for (int i = 0; i != n; ++i) {
            if (i != k) {
                x = lcm(x, a[i]);
            }
        }
        if (x % a[k] != 0) {
            ret = min(ret, x);
        }
    }
    return ret == MAX_INT ? -1 : ret;
}
