#include <vector>
using namespace std;

bool attempt(vector<int> &b) {
    int d = b[1] - b[0];
    for (int i = 2; i < b.size(); ++i) {
        int x = b[i - 1] + d, y = x;
        while (x % 2 == 0) {
            x /= 2;
        }
        if (x != b[i]) {
            return false;
        }
        b[i] = y;
    }
    return true;
}

vector<int> restoreProgression(vector<int> const &a) {
    for (int x = a[0]; ; x *= 2) {
        for (int y = a[1]; y <= 1000 || y < x; y *= 2) {
            vector<int> b(a); b[0] = x; b[1] = y;
            if (attempt(b)) {
                return b;
            }
        }
    }
}
