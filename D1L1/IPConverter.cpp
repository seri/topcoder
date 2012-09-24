#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

bool ok(string const &part) {
    if (part[0] == '0') {
        return part.size() == 1;
    }
    return atoi(part.data()) <= 255;
}

vector<string> possibleAddresses(string const &ip) {
    vector<string> ret;
    for (int a = 1; a <= 3; ++a) {
        for (int b = 1; b <= 3; ++b) {
            for (int c = 1; c <= 3; ++c) {
                for (int d = 1; d <= 3; ++d) {
                    if (a + b + c + d != ip.size()) {
                        continue;
                    }
                    string x = ip.substr(0, a),
                           y = ip.substr(a, b),
                           z = ip.substr(a + b, c),
                           w = ip.substr(a + b + c, d);
                    if (ok(x) && ok(y) && ok(z) && ok(w)) {
                        ostringstream oss;
                        oss << x << '.' << y << '.' << z << '.' << w;
                        ret.push_back(oss.str());
                    }
                }
            }
        }
    }
    sort(begin(ret), end(ret));
    return ret;
}
