#include <algorithm>
using namespace std;

const int MAX = 100000;
const int LIM = 1000000;
vector<int> ps;

bool isPrime(int n) {
    for (auto p : ps) {
        if (p * p > n) {
            return true;
        } else if (n % p == 0) {
            return false;
        }
    }
}

int nthPrime(int n) {
    bool a[LIM]; fill(a, a + LIM, true);
    a[0] = false; a[1] = false; a[2] = true;

    for (int i = 2; i < LIM; ++i) {
        if (!a[i]) {
            continue;
        }
        ps.push_back(i);
        if (ps.size() == n) {
            return i;
        }
        for (int j = i + i; j < LIM; j += i) {
            a[j] = false;
        }
    }

    for (int i = LIM + 1; ; ++i) {
        if (!isPrime(i)) {
            continue;
        }
        ps.push_back(i);
        if (ps.size() == n) {
            return i;
        }
    }
}

int64 smallestNonPrime(int N) {
    int64 p = nthPrime(N + 1);
    return p * p;
}
