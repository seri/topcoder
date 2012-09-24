#include <vector>
#include <string>
#include <cmath>
using namespace std;

int maxCells(int h, int w) {
    if (h == 1 || w == 1) return 1;
    if (h == 2) return min(4, (w + 1)/2);
    if (w >= 7) return w - 2;
    return min(4, w);
}
