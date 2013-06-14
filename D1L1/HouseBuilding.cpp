#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int effort(vector<int> a, int target) {
    int ret = 0;
    for (int x : a) {
        ret += min(abs(x - target), abs(target - 1 - x));
    }
    return ret;
}

int getMinimum(vector<string> const &area) {
    vector<int> a; 
    for (int i = 0; i != area.size(); ++i) {
        for (int j = 0; j != area[i].size(); ++j) {
            a.push_back(area[i][j] - '0');
        }
    }

    int ret = 9 * 50 * 50;
    for (int target = 1; target <= 9; ++target) {
        ret = min(ret, effort(a, target));
    } 
    return ret;
}
