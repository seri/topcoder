#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int merge(vector<int> &a) {
    sort(a.begin(), a.end()); 
    int n = a.size() - 1, top = a[n];
    for (int i = 0; i != n; ++i) {
        int sum = a[i];
        for (int j = 0; sum < top; ++j) {
            if (j == i) continue;
            if (sum < a[j]) break;
            sum += a[j];
        }
        if (sum >= top) return n - i + 1;
    }
    return 1;
}
