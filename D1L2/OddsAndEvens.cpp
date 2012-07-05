#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

void parse(vector<string> const &a, int &evens, int &odds) {
    for (auto elem : a) {
        if (elem == "EVEN") {
            ++evens;
        } else {
            ++odds;
        }
    }
}

/*
    x evens, y odds
    sE even sums, sO odd sums
    pE even sums, pO odd sums
    Then: 
        x(x - 1)/2 + y(y - 1)/2 = sE 
        xy = sO
        y(y - 1)/2 = pO
        xy + x(x - 1)/2 = pE
*/

int equation(int a) {
    return (1 + floor(sqrt((double) (8 * a + 1)))) / 2;
}

bool solve(int sE, int sO, int pE, int pO, int &x, int &y) {
    if (pO == 0) {
        if (sO == 0) {
            y = 0; x = equation(sE);
        } else {
            y = 1; x = sO;
        }
    } else {
        y = equation(pO); x = sO / y;
    }
    return x * y == sO && 
           y * (y - 1) / 2 == pO &&
           x * (x - 1) / 2 == sE - pO && 
           sE - pO == pE - sO;
}

string find(vector<string> const &sums, vector<string> const &products) {
    int sE = 0, sO = 0, pE = 0, pO = 0;
    parse(sums, sE, sO); 
    parse(products, pE, pO);
    
    int x, y;
    if (!solve(sE, sO, pE, pO, x, y)) {
        return "IMPOSSIBLE";
    }
    
    ostringstream oss;
    oss << "EVEN " << x << " ODD " << y;
    return oss.str();
}
