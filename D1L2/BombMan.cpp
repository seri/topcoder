#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
    int x, y, b, t;
};
bool operator < (Node const &p, Node const &q) {
    return p.t > q.t;
}

int shortestPath(vector<string> const &maze, int bombs) {
    int h = maze.size(), 
        w = maze[0].size(),
        x0, y0;

    for (int y = 0; y != h; ++y) {
        for (int x = 0; x != w; ++x) {
            if (maze[y][x] == 'B') {
                x0 = x; 
                y0 = y;
            } 
        }
    }

    priority_queue<Node> nodes;
    Node init = {x0, y0, bombs, 0};
    nodes.push(init);

    bool done[h][w][bombs + 1]; 
    memset(done, false, sizeof(done));

    int dx[] = {-1, 1,  0, 0},
        dy[] = { 0, 0, -1, 1};

    while (!nodes.empty()) {
        Node cur = nodes.top(); nodes.pop();
        int x = cur.x, y = cur.y, b = cur.b, t = cur.t;
        if (done[y][x][b]) {
            continue;
        } else if (maze[y][x] == 'E') {
            return t;
        } else { 
            done[y][x][b] = true;
        }
        
        for (int i = 0; i != 4; ++i) {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 == w || y1 == h || x1 < 0 || y1 < 0) {
                continue;
            }
            char c = maze[y1][x1];
            if (c == '#') {
                if (b > 0) {
                    Node next = {x1, y1, b - 1, t + 3};
                    nodes.push(next);
                }
            } else {
                Node next = {x1, y1, b, t + 1};
                nodes.push(next);
            }
        }     
    }

    return -1;
}
