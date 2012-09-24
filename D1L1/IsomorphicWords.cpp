#include <map>
#include <string>
#include <vector>
using namespace std;

bool isIsormorphic(string const &x, string const &y) {
    map<char, char> a; 
    vector<bool> b(26, false);
    for (int i = 0; i != x.size(); ++i) {
        auto it = a.find(x[i]);
        if (it == a.end()) {
            int j = y[i] - 'a';
            if (b[j]) {
                return false;
            }
            a[x[i]] = y[i];
            b[j] = true;
        } else if (it->second != y[i]) {
            return false;
        }
    }
    return true;
}

int countPairs(vector<string> const &words) {
    int ret = 0;
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            ret += isIsormorphic(words[i], words[j]);
        }
    }
    return ret;
}
