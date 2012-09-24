#include <algorithm>
#include <vector>
using namespace std;

struct Witch {
    int day;
    double win;
    int gain;
};
bool operator<(Witch const &x, Witch const &y) {
    return x.day < y.day;
}

double maxExpectation(int M,
                      vector<int> const &day,
                      vector<int> const &win,
                      vector<int> const &gain) {
    int N = day.size();
    
    vector<Witch> a; Witch dumb = {0, 0, 0}; a.push_back(dumb);
    for (int i = 0; i != N; ++i) {
        Witch witch = {day[i], win[i] / 100.0, gain[i]}; a.push_back(witch);
    }
    sort(begin(a), end(a));

    vector<vector<double>> dp(N + 1, vector<double>(M + 1, 0));
    for (int j = 1; j <= M; ++j) {
        dp[N][j] = a[N].day + j;
    }
    for (int i = N - 1; i >= 0; --i) {
        Witch &x = a[i + 1]; 
        int today = a[i].day, gap = x.day - today;
        for (int j = 1; j <= min(gap, M); ++j) {
            dp[i][j] = today + j;
        }
        for (int j = gap + 1; j <= M; ++j) {
            int life = j - gap;
            dp[i][j] = max(x.win * dp[i + 1][min(M, life + x.gain)] + 
                          (1- x.win) * x.day, dp[i + 1][life]);
        }
    }
    return dp[0][M];
}  
