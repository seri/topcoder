#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string listMostCommon(vector<string> const &text) {
    int a[26]; 
    fill(begin(a), end(a), 0);
    for (auto s : text) {
        for (auto c : s) {
            int i = c - 'a';
            if (i >= 0 && i < 26) {
                ++a[i];
            }
        }
    }
    
    int max = *max_element(begin(a), end(a));
    ostringstream oss;
    for (int i = 0; i != 26; ++i) {
        if (a[i] == max) {
            oss.put(i + 'a');
        }    
    }    
    return oss.str();
}
