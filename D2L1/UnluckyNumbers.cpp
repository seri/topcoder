#include <algorithm>
#include <vector>
using namespace std;

int count(int lower, int upper, int n) {
    return (upper - n + 1) * (n - lower + 1) - 1;
} 

int getCount(vector<int> a, int n) {
    sort(begin(a), end(a));
    for (int i = a.size() - 1; i >= 0; --i) {
        if (n == a[i]) {
            return 0;
        } 
        if (n > a[i]) {
            return count(a[i] + 1, a[i + 1] - 1, n);
        } 
    }
    return count(1, a[0] - 1, n);
}
