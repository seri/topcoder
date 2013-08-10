#include <vector>
#include <string>
using namespace std;

string simulate(vector<int> const &a, vector<int> const &b) {
    int n = a.size();
    string ret(n, '0');

    int ia = 0, ib = 0;
    for (int i = 0; i < n; ++i) {
        while (ia < n && ret[a[ia] - 1] != '0') {
            ++ia;
        }
        if (ia < n) {
            ret[a[ia] - 1] = '1';
        }
        while (ib < n && ret[b[ib] - 1] != '0') {
            ++ib;
        }
        if (ib < n) {
            ret[b[ib] - 1] = '2';
        }
    }

    return ret;
}
