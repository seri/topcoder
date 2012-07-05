#include <vector>
#include <string>
using namespace std;

int count(string const &a) {
    int w = 0, n = a .size(), ret = 0;
    for (int i = 0; i != n; ++i) {
        if (a[i] == 'W') {
            ++w;
        }
    }
    for (int i = w; i != n; ++i) {
        if (a[i] == 'W') {
            ++ret;
        }
    }
    return ret;
}
