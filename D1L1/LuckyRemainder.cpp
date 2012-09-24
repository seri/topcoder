#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void digitize(string const &s, vector<int> &v) {
    v.resize(s.size());
    transform(s.begin(), s.end(), v.begin(), [](char c) { return c - '0'; });
} 
int pow2mod9(int n) {
    static int cycles[] = {1, 2, 4, 8, 7, 5};
    return cycles[n % 6];
} 
int getLuckyRemainder(string const &X) {
    vector<int> v; digitize(X, v); 
    int sum = accumulate(v.begin(), v.end(), 0);
    return ((sum % 9) * pow2mod9(v.size() - 1)) % 9;
}
