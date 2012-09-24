#include <vector>
using namespace std;

int countTheEmptyReds(int maxRank,
                      int maxFile,
                      vector<int> const &rank,
                      vector<int> const &file) {
    int q = 1 - ((maxFile + 1) % 2);
    int reds = (maxRank * maxFile) / 2;
    for (int i = 0; i != rank.size(); ++i) {
        if ((rank[i] + file[i]) % 2 == q) {
            --reds;
        }
    }
    return reds;
}
