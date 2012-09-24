#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

enum Kind {
    ZERO, UNIT, PRIME, COMPOSITE
};

Kind getKind(int a, int b) {
    if (a == 0 && b == 0) {
        return ZERO;
    }
    a = abs(a); b = abs(b);
    if (a > b) {
        swap(a, b);
    }
    if (a == 0) {
        if (b == 1) {
            return UNIT;
        }
        return b % 4 == 3 && isPrime(b) ? PRIME : COMPOSITE;
    }
    return isPrime(a * a + b * b) ? PRIME : COMPOSITE;
}

vector<string> classify(vector<int> const &realPart,
                        vector<int> const &imaginaryPart) {
    vector<string> ret;
    for (int i = 0; i != realPart.size(); ++i) {
        switch (getKind(realPart[i], imaginaryPart[i])) {
            case ZERO: ret.push_back("zero"); break;
            case UNIT: ret.push_back("unit"); break;
            case PRIME: ret.push_back("prime"); break;
            case COMPOSITE: ret.push_back("composite"); break;
        }
    }
    return ret;
}
