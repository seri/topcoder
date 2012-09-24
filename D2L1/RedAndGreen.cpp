#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minPaints(string const &row) {
    int n = row.size(), best = 0, reds = 0;
    for (int i = n - 1; i >= 0; --i) {
        switch (row[i]) {
        case 'R': 
            ++reds;
            break;
        case 'G':
            best = min(best + 1, reds);
        }
    }    
    return best;
}
