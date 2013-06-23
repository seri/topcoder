// The key to solve this problem is the concept Permutation Cycles

#include <vector>
using namespace std;

int reorder(vector<int> const &a) {
    int ret = 0, n = a.size();
    vector<bool> seen(n, false);
    for (int i = 0; i != n; ++i) {
        if (!seen[i]) {
            ++ret;
            for (int j = i; !seen[j]; j = a[j]) {
                seen[j] = true;
            }
        } 
    }
    return ret == 1 ? 0 : ret;
}
