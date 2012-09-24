#include <vector>
#include <string>
using namespace std;

int howManyCards(int D, int L) {
    double x = 0;
    double y = 2.0*D/L;
    for (int i = 1; ; ++i) {
        x += 1.0 / i;
        if (x >= y) {
            return i;
        }
    }
}
