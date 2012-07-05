#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Rec {
    int x1, y1, x2, y2;

    static Rec read(string const &s) {
        istringstream iss(s);
        int x1, y1, x2, y2; 
        iss >> x1 >> y1 >> x2 >> y2;
        Rec ret = {x1, y1, x2, y2};
        return ret;
    }

    int area() const {
        return max(x2 - x1, 0) * max(y2 - y1, 0);
    }

    Rec intersect(Rec const& that) const {
        Rec ret = { max(x1, that.x1), max(y1, that.y1)
                  , min(x2, that.x2), min(y2, that.y2) };
        return ret;
    }
};

int area(vector<string> const &recs) {
    vector<Rec> a(recs.size());
    transform(begin(recs), end(recs), begin(a), Rec::read);

    if (a.size() == 1) {
        return a[0].area();
    }

    Rec x = a[0].intersect(a[1]);
    if (a.size() == 2) {
        return a[0].area() + a[1].area() - x.area();
    }

    Rec y = a[1].intersect(a[2]),
        z = a[2].intersect(a[0]),
        xyz = x.intersect(a[2]);
    return a[0].area() + a[1].area() + a[2].area() - 
           (x.area() + y.area() + z.area()) + xyz.area();
}
