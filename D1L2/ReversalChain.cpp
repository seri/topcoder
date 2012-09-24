#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 51;
const int NEW = -2;
string a, b;
int memo[51][50][50][2];

int go(int n, int i, int j, bool k) {
    if (memo[n][i][j][k] != NEW) {
        return memo[n][i][j][k];
    }
    int ret = INF;

    if (k == 0) {
        if (a[i] == b[j]) {
            ret = min(ret, go(n - 1, i + 1, j + 1, 0));
        }
        if (a[i + n - 1] == b[j + n - 1]) {
            ret = min(ret, go(n - 1, i, j, 0));
        }
        if (a[i] == b[j + n - 1]) {
            ret = min(ret, go(n - 1, i + 1, j, 1) + 1);
        }
        if (a[i + n - 1] == b[j]) {
            ret = min(ret, go(n - 1, i, j + 1, 1) + 1);
        }
    } else {
        if (a[i] == b[j]) {
            ret = min(ret, go(n - 1, i + 1, j + 1, 0) + 1);
        }
        if (a[i + n - 1] == b[j + n - 1]) {
            ret = min(ret, go(n - 1, i, j, 0) + 1);
        }
        if (a[i] == b[j + n - 1]) {
            ret = min(ret, go(n - 1, i + 1, j, 1));
        }
        if (a[i + n - 1] == b[j]) {
            ret = min(ret, go(n - 1, i, j + 1, 1));
        }
    }

    memo[n][i][j][k] = ret;
    return ret;
}

int minReversal(string const &init, string const &goal) {
    a = init; b = goal;
    int n = a.size();
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            memo[0][i][j][0] = 0;
            memo[0][i][j][1] = 0;
            for (int len = 1; len <= n; ++len) {
                memo[len][i][j][0] = NEW;
                memo[len][i][j][1] = NEW;
            }
        }
    }
    int ret = go(n, 0, 0, 0);
    return ret == INF ? -1 : ret;
}
