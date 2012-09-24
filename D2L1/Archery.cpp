#include <vector>
using namespace std;

double expectedPoints(int N, vector<int> const &ringPoints) {
    double ret = 0;
    for (int i = 0; i <= N; ++i) {
        ret += (2 * i + 1) * ringPoints[i];
    }
    return ret /= ((N + 1) * (N + 1));
}
