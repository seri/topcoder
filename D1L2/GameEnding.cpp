#include <vector>
#include <string>
using namespace std;

typedef vector<vector<bool>> Board;
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2}, 
    dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int n;

void put(Board &a, int y, int x) {
    for (int i = 0; i != n; ++i) {
        a[y][i] = true;
        a[i][x] = true;
    }
    for (int i = 0; i != 8; ++i) {
        int yy = y + dy[i], xx = x + dx[i];
        if (yy >= 0 && yy < n && xx >= 0 && xx < n) {
            a[yy][xx] = true;
        }
    }
}

bool play(Board const &a) {
    for (int y = 0; y != n; ++y) {
        for (int x = 0; x != n; ++x) {
            if (!a[y][x]) {
                Board b = a;
                put(b, y, x);
                if (!play(b)) {
                    return true;
                }        
            }
        }
    }
    return false;
}

string result(int N, vector<string> const &moves) {
    n = N; Board a(n, vector<bool>(n, false));
    for (auto move : moves) {
        int y = move[1] - '1', x = move[0] - 'a';
        if (a[y][x]) {
            return "Invalid input";
        }
        put(a, y, x);
    }
    return play(a) ^ (moves.size() % 2) ? "First player wins" 
                                        : "Second player wins";
}
