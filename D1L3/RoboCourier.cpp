#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

bool edges[1001][1001][6];
bool done[1001][1001][6];
int dx[] = {0, 1,  1,  0, -1, -1}, 
    dy[] = {1, 0, -1, -1,  0,  1};
int endx, endy;

struct Node {
    int x, y, t, dir, acc;
};
bool operator<(Node const& p, Node const &q) {
    if (p.t == q.t) return p.acc < q.acc;
    return p.t > q.t;
}

void buildGraph(vector<string> const &path) {
    int dir = 0, x = 500, y = 500;
    for (int i = 0; i != path.size(); ++i) {
        for (int j = 0; j != path[i].size(); ++j) {
            switch (path[i][j]) {
                case 'L': dir = (dir + 5) % 6; break;
                case 'R': dir = (dir + 1) % 6; break;
                case 'F': edges[x][y][dir] = true;
                          x += dx[dir]; y += dy[dir];
                          edges[x][y][(dir + 3) % 6] = true;
            }
        }
    }
    endx = x; endy = y;
}

int timeToDeliver(vector<string> const &path) {
    memset(edges, false, sizeof(edges));
    memset(done, false, sizeof(done));
    buildGraph(path);

    priority_queue<Node> nodes;
    Node init = {500, 500, 0, 0, 0};
    nodes.push(init);

    while (!nodes.empty()) {
        Node node = nodes.top(); nodes.pop();
        int x = node.x, y = node.y, t = node.t, dir = node.dir, acc = node.acc;
        if (x == endx && y == endy) {
            return t;
        } else if (done[x][y][dir]) {
            continue;
        } else {
            done[x][y][dir] = true;
        }

        for (int i = 0; i != 6; ++i) {
            if (!edges[x][y][i]) {
                continue;
            }

            int x1 = x + dx[i], y1 = y + dy[i], t1, acc1;
            if (i == dir) {
                t1 = t + ((acc >= 2) ? 2 : 4);
                acc1 = acc + 1;
            } else {
                int pivot = min((i + 6 - dir) % 6, (dir + 6 - i) % 6);
                t1 = t + 3 * pivot + 4;
                acc1 = 1;
            }

            Node next = {x1, y1, t1, i, acc1};
            nodes.push(next);
        }
    }

    return 0;
}
