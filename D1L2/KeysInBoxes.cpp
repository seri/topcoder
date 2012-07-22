// Stirling's number of the first kind

#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef long long int64;

int64 gcd(int64 x, int64 y) {
    if (y > 0) {
        return gcd(y, x % y);    
    }
    return x;
}

int64 factorial(int n) {
    int64 ret = 1;
    for (int i = 2; i <= n; ++i) {
        ret *= i;
    }
    return ret;
}

string getAllKeys(int N, int M) {
    vector<vector<int64>> a; 
    a.assign(N + 1, vector<int64>(M + 1, 0));
    a[1][1] = 1;
    for (int n = 2; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {
            a[n][m] = a[n - 1][m - 1] + (n - 1) * a[n - 1][m];
        }
    }

    int64 p = 0;
    for (int m = 1; m <= M; ++m) {
        p += a[N][m];        
    }
    int64 q = factorial(N);

    int64 d = gcd(p, q);
    p /= d;
    q /= d;

    ostringstream oss;
    oss << p << '/' << q;
    return oss.str();
}
