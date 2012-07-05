#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef long long int64;

int n;
int64 dp[2][100][100];
int dx[] = {0,  0, 1, -1, 1, -1,  1, -1, 2, -2,  2, -2, 1,  1, -1, -1},
    dy[] = {1, -1, 0,  0, 1, -1, -1,  1, 1,  1, -1, -1, 2, -2,  2, -2};

void clear(bool k) {
    for (int x = 0; x != n; ++x) {
        for (int y = 0; y != n; ++y) {
            dp[k][x][y] = 0;
        }
    }
}

int64 howMany(int size,
              vector<int> const &start,
              vector<int> const &end,
              int numMoves) {
    n = size;
    clear(0); dp[0][start[0]][start[1]] = 1;

    for (int m = 0; m < numMoves; ++m) {
        bool k = m % 2, k0 = !k; clear(k0);
        for (int x = 0; x != n; ++x) {
            for (int y = 0; y != n; ++y) {
                int64 w = dp[k][x][y];
                if (w == 0) {
                    continue;
                }
                for (int i = 0; i != 16; ++i) {
                    int x0 = x + dx[i], y0 = y + dy[i];
                    if (x0 < 0 || y0 < 0 || x0 >= n || y0 >= n) {
                        continue;
                    }
                    dp[k0][x0][y0] += w;
                }
            }
        }
    }

    return dp[numMoves % 2][end[0]][end[1]];
}
