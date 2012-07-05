#include <algorithm>
using namespace std;

int countDead(int n, int row, int col, int hose) {
    int y = max(0, n - (hose/row) * 2);
    int x = max(0, n - (hose/col) * 2);
    return y * x;
}
