#include <vector>
using namespace std; 

int howMany(int A, int B) {
    // a[i] is the number of prime factors of i
    // if a[i] = 0, i is a prime
    vector<int> a(B + 1, 0); 
    a[0] = a[1] = 1;

    for (int i = 2; i <= B; ++i) {
        if (a[i] == 0) {
            for (int j = i + i; j <= B; j += i) {
                for (int k = j; k % i == 0; k /= i) {
                    ++a[j];
                }
            }
        } 
    }

    int ret = 0;
    for (int i = A; i <= B; ++i) {
        if (a[a[i]] == 0) {
            ++ret;
        } 
    }
    return ret;
}
