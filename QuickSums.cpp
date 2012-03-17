#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp[11][11][101];
vector<int> a; int n;
const int UNDONE = -2,
          CANNOT = 11;

void init() {
    for (int lo = 0; lo != n; ++lo) {
        for (int hi = 0; hi != n; ++hi) {
            for (int sum = 0; sum <= 100; ++sum) {
                dp[lo][hi][sum] = UNDONE;
            }
        }
    }
}

int cost(int lo, int hi, int sum) {
    if (dp[lo][hi][sum] != UNDONE) {
        return dp[lo][hi][sum];
    }
    
    int ret = CANNOT, left = 0;
    for (int mid = lo; mid <= hi; ++mid) {
        left = left * 10 + a[mid];
        if (left > sum) {
            break;
        }
        ret = min(ret, 1 + cost(mid + 1, hi, sum - left));
    }
    left = left * 10 + a[hi];
    ret = left == sum ? 0 : ret;

    dp[lo][hi][sum] = ret;
    return ret;
}

int minSums(string const &numbers, int sum) {
    n = numbers.size();
    for (int i = 0; i != n; ++i) {
        a.push_back(numbers[i] - '0');
    }
    init();
    int ret = cost(0, n - 1, sum);
    return ret == CANNOT ? -1 : ret;
}
