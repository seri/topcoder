#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned long long uint64;

const int MAX = 65;
int w, h;
uint64 init, FULL, ONE = 1;

uint64 bit(int y, int x) {
    return ONE << ((y * w) + x);
}

void input(vector<string> const &board) {
    h = board.size(); w = board[0].size(); init = 0; FULL = 0;
    for (int y = 0; y != h; ++y) {
        for (int x = 0; x != w; ++x) {
            auto b = bit(y, x);
            if (board[y][x] == '*') {
                init |= b;
            } 
            FULL |= b;
        }
    }
}

void touch(uint64 &a, int y, int x) {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int xx = x + dx, yy = y + dy;
            if (xx >= 0 && xx < w && yy >= 0 && yy < h) {
                a ^= bit(yy, xx);
            } 
        }
    }
} 

void apply(uint64 &a, int mask) {
    for (int x = 0; x != w; ++x) {
        if (mask & (1 << x)) {
            touch(a, 0, x);
        } 
    }
    for (int y = 1; y != h; ++y) {
        if (mask & (1 << (w + y - 1))) {
            touch(a, y, 0);
        } 
    }
} 

int bitsize(int mask) {
    int ret = 0;
    for (; mask; mask >>= 1) {
        ret += (mask & 1);
    }
    return ret;
} 

int solve(uint64 &a) {
    int ret = 0;
    for (int y = 1; y != h; ++y) {
        for (int x = 1; x != w; ++x) {
            if ((a & bit(y - 1, x - 1)) == 0) {
                touch(a, y, x); 
                ++ret;
            } 
        }
    }
    return a == FULL ? ret : MAX;
} 

int minTouch(vector<string> const &board) {
    input(board);
    int ret = MAX;
    for (int mask = 0; mask < (1 << (w + h - 1)); ++mask) {
        auto a = init; apply(a, mask);
        ret = min(ret, bitsize(mask) + solve(a)); 
    }
    return ret == MAX ? -1 : ret;
}
