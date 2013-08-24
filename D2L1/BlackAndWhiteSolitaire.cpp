#include <string>
#include <algorithm>
using namespace std;

int count(string const &cards, bool start) {
    int ret = 0;
    for (auto card : cards) {
        ret += ((card == 'B') ^ start);
        start = !start;
    }
    return ret;
}

int minimumTurns(string const &cards) {
    return min(count(cards, true), count(cards, false));
}
