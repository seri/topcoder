#include <vector>
using namespace std;

string winner(vector<int> const &a) {
    int i = 0;
    while (i < a.size() && a[i] == 1) {
        ++i;
    }
    return (i % 2 == 0) ^ (i == a.size()) ? "Alice" : "Bob";
}
