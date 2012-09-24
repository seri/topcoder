#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;

vector<int> a;
int beg[1001], end[1001];

bool block(int x, int y) {
    if (beg[x] > end[y] || beg[y] > end[x]) {
        return false;
    }
    return true;
}

vector<int> getOrdering(vector<int> const &height,
                        vector<int> const &bloom,
                        vector<int> const &wilt) {
    a = height; int n = a.size();
    for (int i = 0; i != n; ++i) {
        beg[a[i]] = bloom[i];
        end[a[i]] = wilt[i];
    }
    
    sort(a.begin(), a.end(), greater<int>());
    vector<int> ret(n);
    bool used[n]; memset(used, false, sizeof(used));

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (used[j]) {
                continue;
            }
            int ok = true;
            for (int k = j + 1; k != n; ++k) {
                if (!used[k] && block(a[j], a[k])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ret[i] = a[j];
                used[j] = true;
                break;
            }
        }    
    }

    return ret;
}
