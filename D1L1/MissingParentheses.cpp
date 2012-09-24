#include <vector>
#include <string>
using namespace std;

int countCorrections(string const &par) {
    int p = 0, q = 0;
    for (int i = 0; i != par.size(); ++i) {
        if (par[i] == '(') {
            ++p;
        } else {
            if (p == 0) {
                ++q;
            } else {
                --p;
            }
        }
    }
    return p + q;
}
