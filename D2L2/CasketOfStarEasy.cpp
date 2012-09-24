#include <vector>
#include <algorithm>
using namespace std;

int dp[1024], n;
vector<int> a;

int go(int m) {
    if (dp[m] != -1) {
        return dp[m];
    }
    int ret = 0;

    vector<int> is;
    for (int i = 0; i != n; ++i) {
        if (m & (1 << i)) {
            is.push_back(i);
        }
    }

    for (int j = 1; j < is.size() - 1; ++j) {
        ret = max(ret, a[is[j - 1]] * a[is[j + 1]] + go(m ^ (1 << is[j])));
    }

    dp[m] = ret;
    return ret;
}

int maxEnergy(vector<int> const &weight) {
    n = weight.size(); a = weight;
    fill(dp, dp + 1024, -1);
    return go((1 << n) - 1);
}
