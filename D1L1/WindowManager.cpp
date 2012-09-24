#include <vector>
#include <sstream>
#include <string>
using namespace std;

int H, W;
vector<string> a;

void drawInside(int y1, int x1, int y2, int x2, char c) {
    y1 = max(0, y1); x1 = max(0, x1);
    y2 = min(y2, H - 1); x2 = min(x2, W - 1);
    for (int y = y1; y <= y2; ++y) {
        for (int x = x1; x <= x2; ++x) {
            a[y][x] = c;
        }
    }
}

void drawHorizontal(int y, int x1, int x2) {
    if (y < 0 || y >= H) {
        return;
    }
    x1 = max(0, x1); x2 = min(W - 1, x2);
    for (int x = x1; x <= x2 ; ++x) {
        a[y][x] = '-';
    }
}

void drawVertical(int x, int y1, int y2) {
    if (x < 0 || x >= W) {
        return;
    }
    y1 = max(0, y1); y2 = min(H - 1, y2);
    for (int y = y1; y <= y2; ++y) {
        a[y][x] = '|';
    }
}

void drawCorner(int y, int x) {
    if (y < 0 || y >= H || x < 0 || x >= W) {
        return;
    }
    a[y][x] = '+';
}

void drawBorder(int y1, int x1, int y2, int x2) {
    drawVertical(x1, y1, y2);
    drawVertical(x2, y1, y2);
    drawHorizontal(y1, x1, x2);
    drawHorizontal(y2, x1, x2);
    drawCorner(y1, x1);
    drawCorner(y1, x2);
    drawCorner(y2, x1);
    drawCorner(y2, x2);
}

vector<string> screen(int height, int width, vector<string> const &wins) {
    H = height; W = width; a.assign(H, string(W, ' '));
    for (auto win : wins) {
        istringstream iss(win);
        int y, x, h, w; char c; iss >> y >> x >> h >> w >> c;
        int y1 = y, x1 = x, y2 = y + h - 1, x2 = x + w - 1;
        drawInside(y1 + 1, x1 + 1, y2 - 1, x2 - 1, c);
        drawBorder(y1, x1, y2, x2);
    }
    return a;
}
