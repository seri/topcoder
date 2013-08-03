#include <vector>
#include <string>
using namespace std;

string determineSign(vector<int> const &a) {
    bool pos = true;
    for (auto n : a) {
        if (n == 0) {
            return "ZERO";
        } else if (n < 0) {
            pos = !pos;
        }
    }     
    return pos ? "POSITIVE" : "NEGATIVE";
}
