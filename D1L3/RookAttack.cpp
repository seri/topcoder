#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
using namespace std;

int h, w; 
vector<vector<int>> graph;
vector<int> row; // row[i] -> the column that currently matches row i
vector<int> col; // col[i] -> the row that currently matches column i

bool findPath(int y0) {
    map<int, int> prev; prev[y0] = y0;
    queue<int> ys; ys.push(y0);
    while (!ys.empty()) {
        int y = ys.front(); ys.pop();
        for (int x : graph[y]) {
            int y1 = col[x];
            if (y1 == y) {
                continue;
            }
            if (y1 == -1) {
                while (y != y0) {
                    int oldx = row[y];
                    row[y] = x; col[x] = y;
                    y = prev[y]; x = oldx;
                }
                row[y0] = x; col[x] = y0;
                return true;
            }
            if (prev.find(y1) == prev.end()) {
                ys.push(y1);
                prev[y1] = y;
            }
        }
    }
    return false;
}

set<pair<int, int>> parseCuts(vector<string> const &cutouts) {
    set<pair<int, int>> ret;
    for (auto cutout : cutouts) {
        istringstream iss(cutout);
        while (true) {
            int y, x; iss >> y >> x; 
            ret.insert(make_pair(y, x));
            if (iss.eof()) {
                break;
            }
            iss.ignore(1);
        }
    }
    return ret;
}

void buildGraph(set<pair<int, int>> const &cuts) {
    graph.assign(h, {});
    for (int y = 0; y != h; ++y) {
        for (int x = 0; x != w; ++x) {
            if (cuts.find(make_pair(y, x)) == cuts.end()) {
                graph[y].push_back(x);
            }
        }
    }
}

int howMany(int rows, int cols, vector<string> const &cutouts) {
    h = rows; w = cols; buildGraph(parseCuts(cutouts));
    row.assign(h, -1); col.assign(w, -1);
    
    int ret = 0;
    for (int y = 0; y != h; ++y) {
        ret += findPath(y);
    }
    return ret;
}
