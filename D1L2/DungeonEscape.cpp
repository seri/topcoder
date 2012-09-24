#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int h, w;
int cost[50][50][4];
bool done[50][50];

int dx[] = { 0, 0, 1, -1},
    dy[] = {-1, 1, 0,  0};

struct Node {
    int y, x, t;  
};
bool operator<(Node const &p, Node const &q) {
    return p.t > q.t;
}

int convert(char c) {
    if (c == 'x') {
        return -1;
    }
    return c - '0';
}

int buildCost(vector<string> const &up,
              vector<string> const &down,
              vector<string> const &east,
              vector<string> const &west) {
    for (int y = 0; y != h; ++y) {
        for (int x = 0; x != w; ++x) {
            cost[y][x][0] = convert(up[y][x]);
            cost[y][x][1] = convert(down[y][x]);
            cost[y][x][2] = convert(east[y][x]);
            cost[y][x][3] = convert(west[y][x]);
        }
    }
}

int exitTime(vector<string> const &up,
             vector<string> const &down,
             vector<string> const &east,
             vector<string> const &west,
             int startLevel,
             int startEasting) {
    h = up.size(); w = up[0].size();
    buildCost(up, down, east, west);
    memset(done, false, sizeof(done));

    priority_queue<Node> nodes;
    Node init = {startLevel, startEasting, 0};
    nodes.push(init);

    while (!nodes.empty()) {
        Node node = nodes.top(); nodes.pop();
        int y = node.y, x = node.x, t = node.t;
        if (y < 0) {
            return t;
        }
        if (done[y][x]) {
            continue;
        }
        if (t >= w * (h - y)) {
            continue;
        }
        done[y][x] = true;

        for (int i = 0; i != 4; ++i) {
            int dt = cost[y][x][i];
            if (dt == -1) {
                continue;
            }
            int y1 = y + dy[i], x1 = x + dx[i];
            if (y1 >= h || x1 < 0 || x1 >= w) {
                continue;
            }
            int t1 = t + dt;
            Node next = {y1, x1, t1};
            nodes.push(next);
        }
    }

    return -1;
}
