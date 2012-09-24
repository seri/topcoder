#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int dp[25][25];
const int MAX = 25;
string s;
ostringstream oss;

void init() {
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            dp[i][j] = MAX;
        }
    }
}

int cost(int lo, int hi) {
    if (lo >= hi) {
        return 0;
    } else if (dp[lo][hi] != MAX) {
        return dp[lo][hi];
    }
    int ret = MAX;
    if (s[lo] == s[hi]) {
        ret = cost(lo + 1, hi - 1);
    } else {
        ret = 1 + min(cost(lo + 1, hi), cost(lo, hi - 1));
    }
    dp[lo][hi] = ret;
    return ret;
}

void build(int lo, int hi) {
    if (lo > hi) {
        return;
    } else if (lo == hi) {
        oss << s[lo];
        return;
    } else if (s[lo] == s[hi]) {
        oss << s[lo];
        build(lo + 1, hi - 1);
        return;
    }
    int takelo = cost(lo + 1, hi), takehi = cost(lo, hi - 1);
    if (takelo < takehi || (takelo == takehi && s[lo] < s[hi])) {
        oss << s[lo];
        build(lo + 1, hi);
    } else {
        oss << s[hi];
        build(lo, hi - 1);
    }
}

string shortest(string const &base) {
    s = base; int n = base.size();
    init(); build(0, n - 1);

    string left(oss.str());
    if ((n + cost(0, n - 1)) % 2 == 0) {
        oss << left[left.size() - 1];
    }
    for (int i = left.size() - 2; i >= 0; --i) {
        oss << left[i];
    }

    return oss.str();
}
