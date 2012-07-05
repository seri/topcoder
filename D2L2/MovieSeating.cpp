#include <vector>
#include <string>
using namespace std;

long long perms(int k, int n) {
    long long ret = 1;
    for (int i = n - k + 1; i <= n; ++i)
        ret *= i;
    return ret;
}
long long getSeatings(int k, vector<string> const &hall) {
    long long ret = 0; 
    int h = hall.size(), 
        w = hall[0].size();
    for (int i = 0; i < h; ++i) {
        int n = 0;
        for (int j = 0; j < w; ++j)
            if (hall[i][j] == '.') ++n;            
        ret += perms(k, n);
    }
    for (int j = 0; j < w; ++j) {
        int n = 0;
        for (int i = 0; i < h; ++i)
            if (hall[i][j] == '.') ++n;
        ret += perms(k, n);
    }
    return k == 1 ? ret/2 : ret;
}
