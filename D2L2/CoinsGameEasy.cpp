#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool seen[20][20][20][20];
int dy[] = {-1, 1,  0, 0},
    dx[] = { 0, 0, -1, 1};
int h, w;

struct Pos {
    int y;
    int x;
};

struct Node {
    Pos p;
    Pos q;
    int step;
};

bool inside(Pos const& p) {
    return p.y < h && p.y >= 0 
        && p.x < w && p.x >= 0;
}

int minimalSteps(vector<string> const &board) {
    h = board.size();
    w = board[0].size();

    vector<Pos> initCoins;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (board[y][x] == 'o') {
                initCoins.push_back(Pos{y, x});            
            }
        }
    }

    queue<Node> nodes;
    nodes.push(Node{initCoins[0], initCoins[1], 0});
    memset(seen, false, sizeof seen);

    while (!nodes.empty()) {
        Node node = nodes.front(); nodes.pop();
        Pos p = node.p, q = node.q; int step = node.step;

        switch(inside(p) + inside(q)) {
            case 0: continue;
            case 1: return step;
        }

        if (seen[p.y][p.x][q.y][q.x] || step == 10) {
            continue;
        }
        seen[p.y][p.x][q.y][q.x] = true;
        seen[q.y][q.x][p.y][p.x] = true;

        for (int i = 0; i < 4; ++i) {
            Pos pp = {p.y + dy[i], p.x + dx[i]};
            Pos qq = {q.y + dy[i], q.x + dx[i]};
            if (inside(pp) && board[pp.y][pp.x] == '#') pp = p;
            if (inside(qq) && board[qq.y][qq.x] == '#') qq = q;
            nodes.push(Node{pp, qq, step + 1});
        }
    }

    return -1;
}
