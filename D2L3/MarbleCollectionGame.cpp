#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n; // number of cells
vector<int> a; // marble value at cell i
vector<vector<int>> b; // all adjacent cells of cell i
vector<vector<bool>> c; // is there a path between cell i and cell j

int N; // number of super cells
vector<int> super; // root cell of super cell i
vector<int> A; // total value of super cell i
vector<vector<int>> B; // all adjacent super cells of super cell i
vector<int> dp; // how much can we collect if we start from super cell i

void convert(vector<string> const &board) {
    int h = board.size(), w = board[0].size(), i = 0;
    n = h * w; a.assign(n, 0); b.assign(n, vector<int>());
    for (int y = 0; y != h; ++y) {
        for (int x = 0; x != w; ++x) {
            switch (board[y][x]) {
            case '#':
                break;
            case 'U':
                if (y > 0) {
                    b[i].push_back(i - w);
                }
                break;
            case 'L':
                if (x > 0) {
                    b[i].push_back(i - 1);
                }
                break;
            default:
                a[i] = board[y][x] - '0';
            }
            if (board[y][x] != '#') {
                if (y < h - 1) {
                    b[i].push_back(i + w);
                }
                if (x < w - 1) {
                    b[i].push_back(i + 1);
                }
            }
            ++i;
        }
    }
}

void connect() {
    c.assign(n, vector<bool>(n, false));
    for (int root = 0; root != n; ++root) {
        vector<bool> seen(n, false);
        queue<int> Q; Q.push(root);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            if (seen[u]) {
                continue;
            }
            seen[u] = true;
            for (int w : b[u]) {
                c[root][w] = true;
                Q.push(w);
            }
        }
    }
}

void merge() {
    vector<bool> seen(n, false);
    for (int u = 0; u != n; ++u) {
        if (seen[u]) {
            continue;
        }
        seen[u] = true;
        super.push_back(u);
        int sum = a[u];
        for (int w = 0; w != n; ++w) {
            if (u != w && c[u][w] && c[w][u]) {
                seen[w] = true;
                sum += a[w];
            }
        }
        A.push_back(sum);
    }
    N = A.size(); B.assign(N, vector<int>());
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != N; ++j) {
            if (i != j && c[super[i]][super[j]]) {
                B[i].push_back(j);
            }
        }
    }
    dp.assign(N, -1);
}

int collect(int root) {
    if (dp[root] == -1) {
        int ret = 0;
        for (int u : B[root]) {
            ret = max(ret, collect(u));
        }
        dp[root] = ret + A[root];
    }
    return dp[root];
}

int collectMarble(vector<string> const &board) {
    convert(board);
    connect();
    merge();
    return collect(0);
}
