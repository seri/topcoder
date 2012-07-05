#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int64;

string p, q, r, x, y, z;

//  --- --- ---
// | a | b | c | x
//  --- --- ---
// | d | e | f | y
//  --- --- ---
// | g | h | k | z
//  --- --- ---
//   p   q   r

bool isValid(int a, int b, int d, int e) {
    int g = p.size() - (a + d);
    if (g < 0) {
        return false;
    }
    int h = q.size() - (b + e);
    if (h < 0) {
        return false;
    }
    int c = x.size() - (a + b),
        f = y.size() - (d + e),
        k = z.size() - (g + h);
    if (k < 0) {
        return false;
    }
    return equal(x.begin(), x.begin() + a, p.begin()) 
        && equal(y.begin(), y.begin() + d, p.begin() + a)
        && equal(z.begin(), z.begin() + g, p.begin() + a + d)
        && equal(x.begin() + a, x.begin() + a + b, q.begin())
        && equal(y.begin() + d, y.begin() + d + e, q.begin() + b)
        && equal(z.begin() + g, z.begin() + g + h, q.begin() + b + e)
        && equal(x.begin() + a + b, x.end(), r.begin())
        && equal(y.begin() + d + e, y.end(), r.begin() + c)
        && equal(z.begin() + g + h, z.end(), r.begin() + c + f);
}

int64 getCount(vector<string> const &rowStrings, 
               vector<string> const &columnStrings) {
    x = rowStrings[0]; y = rowStrings[1]; z = rowStrings[2];
    p = columnStrings[0]; q = columnStrings[1]; r = columnStrings[2];
    
    if (x.size() + y.size() + z.size() != 
        p.size() + q.size() + r.size()) {
        return 0;
    }

    int64 ret = 0;
    for (int a = 0; a <= x.size(); ++a) {
        for (int b = 0; b <= x.size() - a; ++b) {
            for (int d = 0; d <= y.size(); ++d) {
                for (int e = 0; e <= y.size() - d; ++e) {
                    ret += isValid(a, b, d, e);
                }
            }
        }
    }
    return ret;
}
 