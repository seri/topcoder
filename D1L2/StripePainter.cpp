#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> a;
int dp[51][51][27];

void compress(string const &s, vector<int> &ret) {
    ret.push_back(s[0] - 'A');
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            ret.push_back(s[i] - 'A');
        }
    }
}

void init() {
    for (int lo = 0; lo != 51; ++lo) {
        for (int hi = 0; hi != 51; ++hi) {
            for (int val = 0; val != 27; ++val) {
                dp[lo][hi][val] = lo > hi ? 0 : -1;
            }
        }
    }
}

int cost(int lo, int hi, int cur) {
    if (dp[lo][hi][cur] != -1) {
        return dp[lo][hi][cur];
    }
    int ret;
    if (a[lo] == cur) {
        ret = cost(lo + 1, hi, cur);
    } else {
        ret = 51;
        for (int mid = lo; mid <= hi; ++mid) {
            if (a[mid] == a[lo]) {
                ret = min(ret, cost(lo, mid, a[lo]) + cost(mid + 1, hi, cur));
            }
        }
        ++ret;
    }
    dp[lo][hi][cur] = ret;
    return ret;
}

int minStrokes(string const &stripes) {
    compress(stripes, a);
    init();
    return cost(0, a.size() - 1, 26); // Apparently 26 is a very ugly color
}