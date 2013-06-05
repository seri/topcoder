#include <vector>
using namespace std;

int getmax(vector<int> const &length) {
    vector<int> a(101, 0);    
    for (auto x : length) {
        ++a[x];
    }

    int ret = 0;
    for (int i = 1; i <= 100; ++i) {
        ret += (a[i] / 2);
    }
    
    return ret;
}
