#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxGames(int coins, vector<int> need, vector<int> give) {
    int n = need.size(), ret = 0; vector<int> cost(n);
    for (int i = 0; i != n; ++i) {
        cost[i] = need[i] - give[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (cost[i] > cost[j]) {
                swap(cost[i], cost[j]);
                swap(need[i], need[j]);
                swap(give[i], give[j]);
            }
        }
    }

    int lowest = *min_element(need.begin(), need.end());
    for (int i = 0; i != n; ++i) {
        int avail = coins - need[i];
        if (avail >= 0) {
            int games = 1 + (avail / cost[i]);
            ret += games;
            coins -= games * cost[i];
            if (coins < lowest) {
                return ret;
            }
        }
    }
    return ret;
}
