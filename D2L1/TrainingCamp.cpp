#include <vector>
#include <string>
using namespace std;

vector<string> determineSolvers(vector<string> const &a,
                                vector<string> const &b) {
    int n = a.size(), m = a[0].size(), k = b.size();
    string empty(k, 'X'); vector<string> ret(n, empty);
    for (int i = 0; i != n; ++i) 
        for (int j = 0; j != k; ++j) 
            for (int x = 0; x != m; ++x) 
                if (a[i][x] == '-' && b[j][x] == 'X')
                {
                    ret[i][j] = '-';
                    break;
                }
    return ret;
}