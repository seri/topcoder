#include <vector>
#include <string>
using namespace std;

string isReachable(vector<string> const &road) {
    static const string NO = "NO";
    static const string YES = "YES";

    int n = road[0].size();
    for (int i = 1; i != n; ++i) {
        if (road[0][i] == 'W' && road[1][i] == 'W') {
            return NO;
        } 
    }
    return YES;
}
