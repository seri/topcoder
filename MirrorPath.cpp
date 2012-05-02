#include <vector>
#include <string>
using namespace std;

vector<string> a;
int w, h;

void left(int y, int x);
void right(int y, int x);
void up(int y, int x);
void down(int y, int x);

void down(int y, int x) {
    for (int i = y; i < h; ++i) {
        switch (a[i][x]) {
        case '#': return;
        case '`': right(i, x + 1); return;
        case '/': left(i, x - 1); return;
        case '-': a[i][x] = '+'; break;
        default : a[i][x] = '|'; break;
        }
    }
}

void up(int y, int x) {
    for (int i = y; i >= 0; --i) {
        switch (a[i][x]) {
        case '#': return;
        case '`': left(i, x - 1); return;
        case '/': right(i, x + 1); return;
        case '-': a[i][x] = '+'; break;
        default : a[i][x] = '|'; break;
        }
    }
}

void left(int y, int x) {
    for (int i = x; i >= 0; --i) {
        switch (a[y][i]) {
        case '#': return;
        case '`': up(y - 1, i); return;
        case '/': down(y + 1, i); return;
        case '|': a[y][i] = '+'; break;
        default : a[y][i] = '-'; break;
        }
    }
}

void right(int y, int x) {
    for (int i = x; i < w; ++i) {
        switch (a[y][i]) {
        case '#': return;
        case '`': down(y + 1, i); return;
        case '/': up(y - 1, i); return;
        case '|': a[y][i] = '+'; break;
        default : a[y][i] = '-'; break;
        }
    }
}

vector<string> path(vector<string> const &map) {
    a = map; h = a.size(); w = a[0].size();
    for (int x = 0; x != w; ++x) {
        if (a[0][x] == '.') {
            down(0, x);
            break;
        } else if (a[h - 1][x] == '.') {
            up(h - 1, x);
            break;
        }
    }
    for (int y = 0; y != h; ++y) {
        if (a[y][0] == '.') {
            right(y, 0);
            break;
        } else if (a[y][w - 1] == '.') {
            left(y, w - 1);
            break;
        }
    }
    return a;
}
