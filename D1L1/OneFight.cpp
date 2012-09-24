#include <algorithm>
#include <vector>
using namespace std;

struct Monster {
    int hp;
    int dp;
};
bool operator< (Monster const &x, Monster const &y) {
    return x.hp * y.dp < y.hp * x.dp;
}

int monsterKilling(vector<int> const &life, 
                   vector<int> const &damage, 
                   int yourDamage) {
    int n = life.size();
    
    vector<Monster> ms;    
    for (int i = 0; i != n; ++i) {
        Monster m = {(life[i] + yourDamage - 1)/yourDamage, damage[i]};
        ms.push_back(m);
    }
    sort(begin(ms), end(ms));
    
    int sum = accumulate(begin(damage), end(damage), 0), ret = 0;
    for (auto m : ms) {
        ret += m.hp * sum;
        sum -= m.dp;
    }
    return ret + 1;
}
