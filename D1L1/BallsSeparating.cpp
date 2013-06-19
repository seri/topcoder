#include <vector>
#include <algorithm>
using namespace std;

int minOperations(vector<int> const &red, 
                  vector<int> const &green, 
                  vector<int> const &blue) {
    int n = red.size();
    if (n < 3) {
        return -1;
    }
    int ret = 150000000;
    for (int r = 0; r < n; ++r) {
        for (int g = 0; g < n; ++g) {
            for (int b = 0; b < n; ++b) {
                if (r == g || b == r || b == g) {
                    continue;
                }
                int temp = green[r] + blue[r] + 
                           red[g] + blue[g] + 
                           red[b] + green[b];
                for (int i = 0; i < n; ++i) {
                    if (i == r || i == g || i == b) {
                        continue;
                    }
                    temp += red[i] + green[i] + blue[i] - 
                            max(red[i], max(green[i], blue[i]));
                }   
                ret = min(ret, temp);
            }
        }
    }
    return ret;
}
