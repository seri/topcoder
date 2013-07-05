#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Teleport {
    Point p;
    Point q;
};

int distance(Point p, Point q) {
    return abs(q.x - p.x) + abs(q.y - p.y);
}

vector<Teleport> parse(vector<string> const &input) {
    vector<Teleport> ret;
    for (auto line : input) {
        int x1, y1, x2, y2; stringstream(line) >> x1 >> y1 >> x2 >> y2;
        Point p = {x1, y1}, q = {x2, y2}; Teleport t = {p, q};
        ret.push_back(t);
    }
    return ret;
}

int64 shortest(Point p, Point q, vector<Teleport> a) {
    int64 ret = distance(p, q);
    for (int i = 0; i < a.size(); ++i) {
        vector<Teleport> b;
        for (int j = 0; j < a.size(); ++j) {
            if (j != i) {
                b.push_back(a[j]);
            }
        }
        ret = min(ret, distance(p, a[i].p) + 10 + shortest(a[i].q, q, b));
        ret = min(ret, distance(p, a[i].q) + 10 + shortest(a[i].p, q, b));
    }
    return ret;
}

int shortestDistance(int xMe, int yMe, int xHome, int yHome,
                     vector<string> const &teleports) {
    Point p = {xMe, yMe}, q = {xHome, yHome};
    return (int) shortest(p, q, parse(teleports));
}
