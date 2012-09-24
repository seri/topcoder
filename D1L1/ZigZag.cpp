#include <vector>
#include <algorithm>
using namespace std;

int longestZigZag(vector<int> const &a) {
    int n = a.size(), dp[n][2];
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != 2; ++j) {
            dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j != i; ++j) {
            if (a[j] > a[i]) {
                dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
            } else if (a[j] < a[i]) {
                dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
            }
        }
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}
