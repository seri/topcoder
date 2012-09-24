#include <algorithm>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Pos;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2},
    dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

string toString(Pos const &p) {
    ostringstream oss;
    oss << p.first << ',' << p.second;
    return oss.str();
}

Pos toPos(string const &s) {
    istringstream iss(s);
    int y, x; iss >> x; iss.ignore(1); iss >> y;
    return make_pair(x, y);
}

vector<Pos> knight(Pos const &p) {
    vector<Pos> ret;
    for (int i = 0; i != 8; ++i) {
        int x = p.first + dx[i];
        int y = p.second + dy[i];
        ret.push_back(make_pair(x, y));
    }
    return ret;
}

vector<string> attackPositions(vector<string> const &pieces) {
    int n = pieces.size();
    
    vector<Pos> poses(n); 
    transform(begin(pieces), end(pieces), begin(poses), toPos);

    vector<vector<Pos>> valids(n);
    transform(begin(poses), end(poses), begin(valids), knight);

    vector<Pos> common(valids[0]); 
    auto first = common.begin(), last = common.end();
    for (int i = 1; i < n; ++i) {
        last = remove_if(first, last, [&](Pos const &p) -> bool {
            return !binary_search(begin(valids[i]), end(valids[i]), p);
        });
    }

    vector<string> ret(last - first);
    transform(first, last, begin(ret), toString);

    return ret;
}
