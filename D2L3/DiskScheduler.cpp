#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;

int cost(int x, int y, int d) {
    x = (x + n) % n; 
    y = (y + n) % n;
    return ((a[y] - a[x]) * d + 100) % 100;
}

int optimize(int start, vector<int> const &sectors) {
    a = sectors; 
    a.push_back(start); 
    sort(begin(a), end(a)); 
    n = a.size();
    
    int k = find(begin(a), end(a), start) - begin(a);
    int ret = 100;

    for (int i = 0; i < n; ++i) {
        ret = min(ret, cost(k, i, -1) + cost(i, i - 1, 1));
        ret = min(ret, cost(k, i, 1) + cost(i, i + 1, -1));
    }

    return ret;
}
