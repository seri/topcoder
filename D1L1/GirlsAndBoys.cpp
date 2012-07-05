#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int arrange(string const &a, char c) {
    int ret = 0;
    for (int i = 0, n = 0; i != a.size(); ++i) {
        if (a[i] == c) {
            ret += i - n;
            ++n;
        }
    }
    return ret;
}

int sortThem(string const &row) {
    return min(arrange(row, 'G'), arrange(row, 'B'));
}
