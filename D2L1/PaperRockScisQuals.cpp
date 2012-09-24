#include <vector>
#include <string>
using namespace std;

int frame(char x, char y) {
    if (x == y) {
        return 0;
    }
    switch (x) {
        case 'P': return y == 'R' ? 1 : -1;
        case 'R': return y == 'S' ? 1 : -1;
        case 'S': return y == 'P' ? 1 : -1;
    }
}

int game(string const &xs, string const &ys) {
    int px = 0, py = 0;
    for (int i = 0; i != 5; ++i) {
        switch (frame(xs[i], ys[i])) {
            case 1: ++px; break;
            case -1: ++py; break;
        }
    }
    if (px == py) {
        return 0;    
    }
    return px > py ? 1 : -1;
}

int whoPassed(vector<string> const &a) {
    int n = a.size();
    vector<int> p(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            switch (game(a[i], a[j])) {
                case 1: p[i] += 2; break;
                case 0: p[i]++; p[j]++; break;
                case -1: p[j] += 2;
            }
        }
    }

    int ret = 0;
    for (int i = 1; i < n; ++i) {
        if (p[i] > p[ret]) {
            ret = i;
        }
    }
    return ret;
}
