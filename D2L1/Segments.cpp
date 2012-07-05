#include <vector>
#include <algorithm>
using namespace std;

void normalise(vector<int> &s) {
    if (s[0] > s[2]) {
        swap(s[0], s[2]);
    }
    if (s[1] > s[3]) {
        swap(s[1], s[3]);
    }
}

string intersection(vector<int> s1, vector<int> s2) {
    normalise(s1); normalise(s2);    
    int x1 = max(s1[0], s2[0]), 
        x2 = min(s1[2], s2[2]),
        y1 = max(s1[1], s2[1]),
        y2 = min(s1[3], s2[3]);
    if (x1 > x2 || y1 > y2) {
        return "NO";
    }
    if (x1 == x2 && y1 == y2) {
        return "POINT";
    }
    return "SEGMENT";
}
