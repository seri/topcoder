#include <algorithm>
#include <vector>
#include <string>
using namespace std;

enum Ordering {
    LT,
    EQ,
    GT
};

template <typename T>
Ordering compare(T const &x, T const &y) {
    if (x < y) {
        return LT;
    } else if (x > y) {
        return GT;
    } else {
        return EQ;
    }
}

int sumDigits(string const &x) {
    int ret = 0;
    for (auto c : x) {
        if (c >= '0' && c <= '9') {
            ret += c - '0';
        }    
    }
    return ret;
}

bool compareSerials(string const &x, string const &y) {
    switch (compare(x.size(), y.size())) {
    case LT: return true;
    case GT: return false;
    case EQ:
        switch (compare(sumDigits(x), sumDigits(y))) {
        case LT: return true;
        case GT: return false;
        case EQ: return x < y;
        }
    }
}

vector<string> sortSerials(vector<string> a) {
    sort(begin(a), end(a), compareSerials);
    return a;
}
