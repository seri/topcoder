#include <vector>
#include <algorithm>
using namespace std;

int linear(vector<int> const &a, int lo, int hi) {
    if (lo == hi) {
        return a[lo];
    }
    int dp[40];
    dp[lo] = a[lo]; dp[lo + 1] = max(a[lo], a[lo + 1]);
    for (int i = lo + 2; i <= hi; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }
    return dp[hi];
}

int circular(vector<int> const &a) {
    int n = a.size();
    return max(linear(a, 0, n - 2), linear(a, 1, n - 1));
}

int maxDonations(vector<int> const &a) {
    return circular(a);
}
