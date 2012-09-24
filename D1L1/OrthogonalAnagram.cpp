#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a[256], d[256];
char b[50], c[50];
int n;

bool impossible(int k) {
    int len = n - k;
    fill(d, d + 256, 0);
    for (char *p = b + k; p != b + n; ++p) {
        ++d[*p];
        if (d[*p] + a[*p] > len) {
            return true;
        }
    }
    return false;
}

bool recurse(int k) {
    if (k == n) {
        return true;
    }
    if (impossible(k)) {
        return false;
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        if (a[i] == 0 || i == b[k]) {
            continue;
        }
        --a[i];
        c[k] = i;
        if (recurse(k + 1)) {
            return true;
        }
        ++a[i];
    }
}

string solve(string const &s) {
    n = s.size();
    copy(s.begin(), s.end(), b);
    
    fill(a, a + 256, 0);
    for (auto it = s.begin(); it != s.end(); ++it) {
        ++a[*it];
    }

    return recurse(0) ? string(c, n) : "";
}
