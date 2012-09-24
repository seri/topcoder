#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int N, D;
int mins[50];
int vals[50];
vector<vector<int>> rooms;
int costs[50];
int dp[50][1000];

void readDoors(vector<int> const &doors) {
    N = doors.size();
    mins[0] = doors[0];
    for (int i = 1; i != N; ++i) {
        mins[i] = min(mins[i - 1], doors[i]);
    }
}

void readDiamonds(vector<string> const &diamonds) {
    D = diamonds.size(); 
    rooms.resize(N);
    for (int i = 0; i != D; ++i) {
        istringstream iss(diamonds[i]);
        iss >> vals[i] >> costs[i];
        int room; iss >> room;
        rooms[room - 1].push_back(i);
    }
}

int go(int room, int t) {
    if (dp[room][t] != -1) {
        return dp[room][t];
    } 
    int ret = 0;

    int avail = mins[room] - t;
    for (auto i : rooms[room]) {
        if (costs[i] < avail) {
            ret = max(ret, vals[i] + go(room, t + costs[i]));
        }
    }
    if (room > 0) {
        ret = max(ret, go(room - 1, t));
    } 

    dp[room][t] = ret;
    return ret;
}

int robTheBank(vector<int> const &doors, vector<string> const &diamonds) {
    readDoors(doors); readDiamonds(diamonds);
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != 1000; ++j) {
            dp[i][j] = -1;
        }
    }
    return go(N - 1, 0);
}
