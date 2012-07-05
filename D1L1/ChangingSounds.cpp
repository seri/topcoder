#include <vector>
#include <cstring>
using namespace std;

int maxFinal(vector<int> const &a, int start, int limit) {
    int n = a.size(); 
    
    bool b[n + 1][limit + 1];
    memset(b, false, sizeof(b));
    
    b[0][start] = true;    
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j <= limit; ++j) {
            if (b[i][j]) {
                if (j >= a[i]) {
                    b[i + 1][j - a[i]] = true;
                }
                if (j + a[i] <= limit) {
                    b[i + 1][j + a[i]] = true;
                }
            }
        }
    }

    for (int j = limit; j >= 0; --j) {
        if (b[n][j]) {
            return j;
        }
    }
    return -1;
}
