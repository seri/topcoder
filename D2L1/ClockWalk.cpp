#include <vector>
#include <string>
using namespace std;

int finalPosition(string const &flips) {
    int ret = 0;
    for (int i = 0; i != flips.size(); ++i) {
        if (flips[i] == 'h') {
            ret = (ret + i + 1) % 12;
        } else {
            ret = (ret + 59 - i) % 12;
        }
    }
    return ret == 0 ? 12 : ret;
}
