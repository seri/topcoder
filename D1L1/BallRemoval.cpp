#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

bool memo[50][50];
bool done[50][50];
int n;
string a;

// Can the substring from l to r (inclusive) be removed entirely by itself?
bool canRemove(int l, int r) {
    if (l > r) {
        return true;
    }
    if (l == r) {
        return false;
    }
    if (done[l][r]) {
        return memo[l][r];
    }

    bool ret = false;

    // Try selecting the last chosen ball such that this ball will remove the entire substring
    for (int last = max(l, 1); last <= min(r, n - 2); ++last) {
        if (a[last] == '<') {
            if (!canRemove(last + 1, r)) {
                continue;
            }
            for (int i = l; i < last; ++i) {
                if (canRemove(l, i - 1) && canRemove(i + 1, last - 1)) {
                    ret = true;
                    goto finally;
                }
            }
        } else {
            if (!canRemove(l, last - 1)) {
                continue;
            }
            for (int i = last + 1; i <= r; ++i) {
                if (canRemove(last + 1, i - 1) && canRemove(i + 1, r)) {
                    ret = true;
                    goto finally;
                }
            }
        }
    }

finally:
    done[l][r] = true;
    memo[l][r] = ret;
    return ret;
}

string canLeave(string const &label) {
    a = label; n = a.size();
    memset(done, false, sizeof done);

    ostringstream ret;
    for (int i = 0; i < n; ++i) {
        if (canRemove(0, i - 1) && canRemove(i + 1, n - 1)) {
            ret << 'o';
        } else {
            ret << '.';
        }
    }

    return ret.str();
}
