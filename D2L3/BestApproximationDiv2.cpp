#include <vector>
#include <string>
#include <sstream>
using namespace std;

int quality(int a, int b, vector<int> const &d) {
    int x = 1;
    for (int i = 0; i != d.size(); ++i) {
        int aa = 10 * a;
        if (aa/b == d[i]) {
            a = aa % b;
            ++x;
        } 
        else break;
    }
    return x;
}
double todec(vector<int> const &d, int n) {
    double ret = 0;
    for (int i = 0, j = 10; i != n; ++i) {
        ret += (double)(d[i]) / j;
        j *= 10;
    }
    return ret;
}
bool update(int a, int b, vector<int> const &d, 
            int &retx, int &reta, int &retb, double &y) {
    int x = quality(a, b, d);
    if (x > retx) {
        retx = x; reta = a; retb = b;
        y = todec(d, x - 1);
        return true;
    } 
    return (x == retx);
}
string findFraction(int maxDen,
                    string const &number) {
    vector<int> d;
    for (int i = 2; i != number.size(); ++i)
        d.push_back(number[i] - '0');

    int retx = 0, reta, retb; 
    double y = 0;
    for (int b = 1; b <= maxDen; ++b) {
        int pivot = y*b;
        for (int a = pivot; a >= 0; --a)
            if (!update(a, b, d, retx, reta, retb, y)) break;
        for (int a = pivot + 1; a < b; ++a)
            if (!update(a, b, d, retx, reta, retb, y)) break;
    }

    ostringstream oss;
    oss << reta << '/' << retb << " has " << retx << " exact digits";
    return oss.str();
}
