#include <vector>
using namespace std;

int maxTurns(vector<int> const &cards) {
    bool a[502]; 
    fill(a, a + 502, false);
    
    for (int i = 0; i < cards.size(); ++i)
        a[cards[i]] = true;

    int ret = 0;
    for (int i = 1; i <= 500; ++i) 
        if (a[i]) {
            if (a[i + 1]) ++i;
            ++ret;
        }        

    return ret;
}
