#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
using namespace std;

typedef long long int64;

int n, smax;
vector<int> a;
int64 lo[31][30001], hi[31][30001];
vector<pair<int, int>> groups;

void reverse() {
    for (int i = 0; i < (n/2); ++i) {
        swap(a[i], a[n - 1 - i]);
    }
}

int64 choose(int takes, int total) {
    int64 ret = 1;
    for (int i = 1; i <= takes; ++i) {
        ret *= total--;
        ret /= i;
    }
    return ret;
}

void countWays(int64 ret[31][30001]) {
    ret[0][0] = 1;
    for (int s = 1; s <= smax; ++s) {
        ret[0][s] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s <= smax; ++s) {
            ret[i][s] = ret[i - 1][s];
            if (s >= a[i - 1]) {
                ret[i][s] += ret[i - 1][s - a[i - 1]];
            }
        }
    }
}

void makeGroups() {
    for (int i = 1, pos = 1; i <= n; ++i) {
        if (i == n || a[i] != a[pos - 1]) {
            groups.push_back(make_pair(pos, i - pos + 1));
            pos = i + 1;
        }
    }
}

int64 howMany(vector<int> const &values) {
    a = values; n = a.size(); smax = accumulate(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), greater<int>()); countWays(hi);
    reverse(); countWays(lo); makeGroups();

    int64 ret = 0;
    for (int i = 0; i != groups.size(); ++i) {
        int pos = groups[i].first, len = groups[i].second, x = 0;
        for (int j = 1; j <= len; ++j) {
            x += a[pos - 1];
            for (int s = x; s <= smax; ++s) {
                ret += lo[pos - 1][s - x] * 
                       hi[n - (pos + j - 1)][s] * 
                       choose(j, len);
            }
        }
    }
    return ret;
}
