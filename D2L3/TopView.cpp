// Requires [Topological Sort](http://en.wikipedia.org/wiki/Topological_sort)

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string const ERROR = "ERROR!";

vector<string> a;
vector<int> cards;

const int N = 10 + 26 + 26;
char indexToCard[N];
int cardToIndex[256];

vector<vector<int>> above(N);
vector<int> under(N, 0);

void setupConverters() {
    for (char c = '0'; c <= '9'; ++c) {
        indexToCard[c - '0'] = c;
        cardToIndex[c] = c - '0';
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        indexToCard[c - 'A' + 10] = c;
        cardToIndex[c] = c - 'A' + 10;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        indexToCard[c - 'a' + 36] = c;
        cardToIndex[c] = c - 'a' + 36;
    }
}

bool findConstraints() {
    int H = a.size(), W = a[0].size();
    for (int i = 0; i < N; ++i) {
        int x1 = 50, y1 = 50, x2 = -1, y2 = -1;
        bool found = false;
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (indexToCard[i] == a[y][x]) {
                    found = true;
                    x1 = min(x, x1);
                    y1 = min(y, y1);
                    x2 = max(x, x2);
                    y2 = max(y, y2);
                }
            }
        }
        if (found) {
            cards.push_back(i); 
            for (int y = y1; y <= y2; ++y) {
                for (int x = x1; x <= x2; ++x) {
                    if (a[y][x] == '.') {
                        return false;
                    }
                    int j = cardToIndex[a[y][x]];
                    if (j != i) {
                        above[i].push_back(j);
                        under[j]++;
                    }
                }
            }
        }
    }
    return true;
} 

string topoSort() {
    ostringstream oss;
    for (int k = 0; k < cards.size(); ++k) {
        bool found = false;
        for (int i : cards) {
            if (under[i] == 0) {
                found = true;
                for (int j : above[i]) {
                    under[j]--;
                }
                under[i] = -1;
                oss << indexToCard[i];
                break;
            }
        }
        if (!found) {
            return ERROR;
        }
    }
    return oss.str();
}

string findOrder(vector<string> const &grid) {
    a = grid;
    setupConverters();
    if (!findConstraints()) {
        return ERROR;
    }
    return topoSort();
}