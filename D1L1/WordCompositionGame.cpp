#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void analyse(map<string, int> &dic, vector<string> const &list) {
    for (auto word : list) {
        ++dic[word];
    }
}

int compute(map<string, int> &dic, vector<string> const &list) {
    int ret = 0;
    for (auto word : list) {
        ret += (4 - dic[word]);
    }
    return ret;
}

string score(vector<string> const &listA,
             vector<string> const &listB,
             vector<string> const &listC) {
    map<string, int> dic;
    analyse(dic, listA); 
    analyse(dic, listB); 
    analyse(dic, listC);

    ostringstream oss;
    oss << compute(dic, listA) << '/' 
        << compute(dic, listB) << '/' 
        << compute(dic, listC);
    return oss.str();
}
