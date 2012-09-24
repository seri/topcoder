#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
bool can[16][16];
vector<int> init;

void readKnowledge(string const &knowledge) {
    int know = 0;
    for (int i = 0; i != n; ++i) {
        if (knowledge[i] == 'Y') {
            know |= (1 << i);
        }
    }
    init = {know, know};
}

void readGraph(vector<string> const &graph) {
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            can[i][j] = graph[i][j] == 'Y';
        }
    }
}

void spread(int rabbit, int &know) {
    for (int i = 0; i != n; ++i) {
        if (can[rabbit][i]) {
            know |= (1 << i);
        }
    }
}

bool filled(vector<int> const &a) {
    return (a[0] == (1 << n) - 1) 
        && (a[1] == (1 << n) - 1);
}

int getMinimum(string const &knowledge, vector<string> const &graph) {
    n = knowledge.size();
    readKnowledge(knowledge); 
    readGraph(graph);

    int best = 100;

    for (int order = 0; order < (1 << n); ++order) {
        auto a(init);
        int once = 0, twice = 0; 
        
        for (int day = 0; day < best; ++day) {
            if (filled(a)) {
                best = min(best, day);
                break;
            }

            auto b(a); 

            for (int i = 0; i != n; ++i) {
                int bit = 1 << i;
                if (twice & bit) {
                    continue;
                }

                bool rumor = ((order & bit) > 0) ^ ((once & bit) > 0);
                if (a[rumor] & bit) {
                    spread(i, b[rumor]);
                    if (once & bit) {
                        twice |= bit;
                    } else {
                        once |= bit;
                    }
                }
            }

            if (a[0] == b[0] && a[1] == b[1]) {
                break;
            }
            a = b;
        }
    }

    return best == 100 ? -1 : best;
}
