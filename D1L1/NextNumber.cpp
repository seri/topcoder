#include <vector>
#include <string>
using namespace std;

// See:
// http://apps.topcoder.com/forums/?module=Thread&threadID=623482&start=0

int getNextNumber(int N) {
                // Suppose N = 10101110 
    int a = N & (-N);   // a = 00000010
    int b = N + a;      // b = 10110000
    int c = N ^ b;      // c = 00011110
    int d = c / a;      // d = 00001111
    int e = d >> 2;     // e = 00000011
    return b | e;     // ret = 10110011
}
