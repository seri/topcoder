#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int INF = 1000;
vector<string> a; 
int n, b[50], c[50];

void dfs(int x, int cost) {
    if (cost >= c[x] || cost == b[x]) {
        return;
    }

    if (cost < b[x]) {
        c[x] = b[x];
        b[x] = cost;
    } else {
        c[x] = cost;
    }

    for (int i = 0; i != n; ++i) {
        if (a[x][i] != 'X') {
            dfs(i, cost + a[x][i] - '0');
        }
    }
}

int secondBest(vector<string> const &graph, int from, int to) {
    a = graph; n = a.size();
    fill(b, b + n, INF);
    fill(c, c + n, INF);
    
    dfs(from, 0);
    return c[to] == INF ? -1 : c[to];
}
