#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

double const MARGIN = 1e-9;

int convert(char c) {
    return c == '0' ? 0 : 1;
}

double compute(double base, vector<int> const &a) {
    double ret = 0, x = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        ret += x * a[i];
        x *= base;
    }
    return ret;
}

double binary(double age, vector<int> const &a, double lo, double hi) {
    double base = (lo + hi)/2;
    double temp = compute(base, a);
    double diff = temp - age;
    if (abs(diff) < MARGIN) {
        return base;
    } else if (diff > 0) {
        return binary(age, a, lo, base);
    } else {
        return binary(age, a, base, hi);
    }
}

double getRadix(int age, string const &candlesLine) {
    vector<int> a(candlesLine.size());
    transform(begin(candlesLine), end(candlesLine), begin(a), convert);
    int sum = accumulate(begin(a), end(a), 0);
    if (sum == 0) {
        return -1;
    } else if (a[a.size() - 1] == 1) {
        if (sum == 1) {
            return age == 1 ? -2 : -1;
        } else if (age == 1) {
            return -1;
        }
    }
    return binary((double) age, a, 0, 100);
}
