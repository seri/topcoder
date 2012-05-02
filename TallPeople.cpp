#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> a;

void parse(vector<string> const &people) {
    for (auto row : people) {
        vector<int> v;
        istringstream iss(row);
        while (iss.good()) {
            int j; iss >> j; v.push_back(j);
        }
        a.push_back(v);
    }
}

vector<int> getPeople(vector<string> const &people) {
    parse(people);
    int tallest = 0, shortest = 1001;
    for (auto row : a) {
        tallest = max(tallest, *min_element(begin(row), end(row)));
    }
    for (int x = 0; x != a[0].size(); ++x) {
        int cur = 0;
        for (int y = 0; y != a.size(); ++y) {
            cur = max(cur, a[y][x]);
        }
        shortest = min(shortest, cur);
    }
    return {tallest, shortest};
}
