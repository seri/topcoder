// Solution explained: http://apps.topcoder.com/wiki/display/tc/SRM+565

const int MOD = 1000000009;

long long modPow(int p, int q) {
    if (q == 0) {
        return 1;
    } else if (q == 1) {
        return p;
    }
    long long ret = modPow(p, q/2);
    return ret * ret % MOD * modPow(p, q % 2) % MOD;
}

long long combination(int n, int k) {
    long long upper = 1;
    for (int i = n; i > n - k; --i) {
        upper = upper * i % MOD;
    }
    long long lower = 1;
    for (int i = 1; i <= k; ++i) {
        lower = lower * i % MOD;
    }
    return upper * modPow(lower, MOD - 2) % MOD;
}

int count(int n, int h) { 
    long long ret = 1;
    for (int p = 2; p <= n/p; ++p) { 
        int q = 0;
        while (n % p == 0) {
            ++q;
            n /= p;
        } 
        ret = ret * combination(h - 1 + q, q) % MOD;
    }
    if (n > 1) {
        ret = ret * h % MOD;
    } 
    return (int) ret;
}
