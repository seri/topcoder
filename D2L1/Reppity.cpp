#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int longestRep(string const &input) {
    int n = input.size(); 
    auto pb = begin(input), pe = end(input);
    
    for (int len = n/2; len > 0; --len) {
        for (auto p = pb; p <= pb + input.size() - 2*len; ++p) {
            if (search(p + len, pe, p, p + len) != pe) {
                return len;
            }
        }
    }
    
    return 0;
}
