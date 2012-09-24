#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int h, w;

int area(vector<string> const &board, int y1, int x1, int y2, int x2) {
    int n = 0;
    for (int y = y1; y <= y2; ++y) {
        for (int x = x1; x <= x2; ++x) {
            if (board[y][x] == 'o') {
                n += 1;
            }
        }
    }
    return n;
} 

int cost(int y1, int x1, int y2, int x2) {
    int y3 = h - 1 - y2, x3 = w - 1 - x2;
    return x1 + y1 + x3 + y3 + min(x1, x3) + min(y1, y3);
}

int getMinimum(vector<string> const &board, int k) {
    h = board.size(); w = board[0].size();
    int n = area(board, 0, 0, h - 1, w - 1);
    if (k > n) {
        return -1;
    }
    if (k == n) {
        return 0;
    } 
    int ret = 27000;
    for (int y1 = 0; y1 != h; ++y1) {
        for (int x1 = 0; x1 != w; ++x1) {
            for (int y2 = y1; y2 != h; ++y2) {
                for (int x2 = x1; x2 != w; ++x2) {
                    if (area(board, y1, x1, y2, x2) == k) {
                         int x = cost(y1, x1, y2, x2);
                         if (x == 1) {
                             return x;
                         }
                         if (x < ret) {
                             ret = x;
                         }
                    }
                }
            }
        }
    }
    return ret == 27000 ? -1 : ret;
}

