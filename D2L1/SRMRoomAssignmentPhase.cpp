#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool gt(int x, int y) {
    return x > y;
}

int countCompetitors(vector<int> a, int k) {
    int x = a[0], ret = 0;
    sort(a.begin(), a.end(), gt);
    int p = (find(a.begin(), a.end(), x) - a.begin()) % k;
    for (int i = p; i < a.size(); i += k) {
        if (a[i] > x) {
            ++ret;
        }
    }
    return ret;
}
