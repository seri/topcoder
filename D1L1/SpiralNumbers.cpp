#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int sqr(int x) {
    return x * x;
}

int compute(int n, int &k, int &p, int &q) {
    int x = floor(sqrt((double) n));
    k = (x - 1)/2;
    if (sqr(x) == n) {
        --k;
    }
    int m = n - (sqr(2*k + 1) + 1);
    int r = 2*k + 2;
    p = m / r; q = m % r;
}

void spiral(int n, int &y, int &x) {
    int k, p, q; compute(n, k, p, q);
    switch (p) {
    case 0: 
        x = k + 1;
        y = (-k) + q;
        break;
    case 1:
        y = k + 1;
        x = k - q;
        break;
    case 2:
        x = -(k + 1);
        y = k - q;
        break;
    case 3:
        y = -(k + 1);
        x = (-k) + q;
    }
}

string getPosition(int N) {
    if (N == 1) {
        return "(0,0)";
    }
    int y, x; spiral(N, y, x);
    ostringstream oss;
    oss << '(' << y << ',' << x << ')';
    return oss.str();
}
