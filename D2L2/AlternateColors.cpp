#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Ball {
public:
    string name;
    int64 number;

    Ball(string const &name, int64 number) 
        : name(name), number(number) {}
};
bool operator< (Ball const &x, Ball const &y) {
    return x.number < y.number;
}

string getColor(int64 r, int64 g, int64 b, int64 k) {
    vector<Ball> a = { Ball("RED", r)
                     , Ball("GREEN", g)
                     , Ball("BLUE", b) };
    while (!a.empty()) {
        int64 y = min_element(begin(a), end(a))->number;

        int64 x = y * a.size();
        if (x >= k) {
            return a[(k + a.size() - 1) % a.size()].name;
        }
        k -= x;

        vector<Ball> b = a; a.clear();
        for (Ball& ball : b) {
            if ((ball.number -= y) > 0) {
                a.push_back(ball);
            }
        }
    }
}
