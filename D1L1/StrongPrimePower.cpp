#include <vector>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

bool is_prime(int n) { 
    for (int i = 2; (i * i) <= n; ++i)
        if (n % i == 0) return false;
    return true;
} 
long long bin_pow(int p, int q) {
    if (q == 0) return 1;
    if (q == 1) return p;
    long long n = bin_pow(p, q / 2);
    return n * n * bin_pow(p, q % 2);
} 
vector<int> base_exp(long long n) {
    int retp, retq = 1;

    for (int q = 2; retq == 1 && q != 60; ++q) {
        int p = round(pow(n, 1.0 / q));
        if (is_prime(p) && bin_pow(p, q) == n) {
            retp = p;
            retq = q;
        }         
    }

    vector<int> ret; 
    if (retq > 1) {
        ret.push_back(retp); 
        ret.push_back(retq); 
        return ret;
    } 
    else return ret;
}
vector<int> baseAndExponent(string const &n) {
    long long x; istringstream iss(n); iss >> x;
    return base_exp(x);
}
