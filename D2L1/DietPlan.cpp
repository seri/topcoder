#include <vector>
#include <string>
#include <sstream>
using namespace std;

int toMask(string const &s) {
    int ret = 0;
    for (auto c : s) {
        ret |= (1 << (c - 'A'));
    }
    return ret;
}

string toString(int mask) {
    ostringstream oss;
    for (int i = 0; mask; ++i) {
        if (mask & 1) {
            oss.put(i + 'A');
        }
        mask >>= 1;
    }
    return oss.str();
}

string chooseDinner(string const &diet,
                    string const &breakfast,
                    string const &lunch) {
    int x = toMask(diet);
    int y = toMask(breakfast) | toMask(lunch);
    int ret = x ^ y; 
    return (ret & x) == ret ? toString(ret) : "CHEATER";
}
