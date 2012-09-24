#include <vector>
#include <string>
using namespace std;

int sumDigits(int n, int base) {
    int ret = 0;
    while (n > 0) {
        ret += (n % base);
        n /= base;
    }
    return ret;
}

bool cool(int digit, int base) {
    int max = base * base * base * base;
    for (int i = digit + digit; i < max; i += digit) {
        if (sumDigits(i, base) % digit != 0) {
            return false;
        }
    }
    return true;
}

vector<int> digits(int base) {
    vector<int> ret;
    for (int i = 2; i != base; ++i) {
        if (cool(i, base)) {
            ret.push_back(i);
        }
    }
    return ret;
}
