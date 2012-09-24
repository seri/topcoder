#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int count(string const &dithered, vector<string> const &screen) {
    bool a[26]; fill(a, a + 26, false);
    for (auto c : dithered) {
        a[c - 'A'] = true;
    }
    int ret = 0;
    for (auto line : screen) {
        for (auto c : line) {
            ret += a[c - 'A'];    
        }
    }
    return ret;
}
