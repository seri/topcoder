int modulus(int b, int n, int p) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return b % p;
    }
    int k = modulus(b, n/2, p);
    return ((k * k % p) * modulus(b, n % 2, p)) % p;
}

int firstFail(int q) {
    for (int b = 2; b < q; ++b) {
        if (modulus(b, q - 1, q) != 1) {
            return b;
        }
    }
    return q;
}
