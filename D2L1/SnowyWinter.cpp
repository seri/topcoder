#include <vector>
#include <algorithm>
using namespace std;

int snowyHighwayLength(vector<int> const &begs, vector<int> const &ends) {
    vector<int> a(10001, 0);
    for (int i = 0; i != begs.size(); ++i) {
        for (int j = begs[i]; j < ends[i]; ++j) {
            a[j] = 1;
        }    
    }
    return accumulate(begin(a), end(a), 0);
}
