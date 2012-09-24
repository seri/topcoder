#include <vector>
#include <string>
using namespace std;

vector<string> aftermath(vector<string> const &board) {
    int w = board[0].size(), 
        h = board.size();

    vector<int> depths; int dmin = 51;
    for (int x = 0; x < w; ++x) {
        int depth = 0;
        for (int y = 0; y < h; ++y)
            if (board[y][x] == 'X') ++depth;            
        depths.push_back(depth);
        if (depth < dmin) dmin = depth;
    }
    for (int i = 0; i < depths.size(); ++i)
        depths[i] -= dmin;

    string none(w, '.');
    vector<string> ret(h, none);
    for (int x = 0; x < w; ++x)
        for (int y = 0; y < depths[x]; ++y)
            ret[h - y - 1][x] = 'X';
    return ret;
}