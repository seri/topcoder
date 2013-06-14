#include <vector>
#include <cstring>
using namespace std;

bool prime[100];

void buildPrime() {
    memset(prime, true, 100); prime[0] = false; prime[1] = false;
    for (int i = 2; i < 100; ++i) {
        if (prime[i]) {
            for (int j = i + i; j < 100; j += i) {
                prime[j] = false;
            }
        }
    }       
}

bool coolDigits(vector<int> v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (prime[10 * v[i] + v[j]] || prime[10 * v[j] + v[i]]) {
                return true;
            }
        }
    }
    return false;
}

vector<int> toDigits(int n) {
    vector<int> ret;
    while (n != 0) {
        int d = n % 10;
        if (d != 0) {
            ret.push_back(d);
        }
        n /= 10;
    }
    return ret;
}

int countNumbers(int a, int b) {
    buildPrime();
    int ret = 0;
    for (int n = a; n <= b; ++n) {
        if (coolDigits(toDigits(n))) {
            ++ret;
        }
    }
    return ret;
}
