#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int calcRanks(int k, vector<int> const &scores) {
    int n = scores.size(), ret = n;
    for (int i = 0; i != n; ++i) {
        for (int j = i - 1; j >= max(i - k, 0); --j) {
            ret += (scores[i] < scores[j]);
        }
    }
    return ret;
}
