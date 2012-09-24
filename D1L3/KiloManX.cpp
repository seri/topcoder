#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int state;
    int shots;
    Node(int state, int shots) : state(state), shots(shots) { }
};

bool operator<(Node const& left, Node const &right) {
    return left.shots > right.shots;
}

int leastShots(vector<string> const &weapons, 
               vector<int> const &bosses) {
    int n = weapons.size(), m = 1 << n;
    bool done[m]; fill(done, done + m, false); --m;

    priority_queue<Node> nodes;
    nodes.push(Node(0, 0));

    while (!nodes.empty()) {
        Node node = nodes.top(); nodes.pop();

        int state = node.state, shots = node.shots;
        if (done[state]) {
            continue;
        }
        done[state] = true;

        if (state == m) {
            return shots;
        }

        for (int boss = 0; boss != n; ++boss) {
            if ((state >> boss) & 1) {
                continue;
            }

            int best = 1;
            for (int weapon = 0; weapon != n; ++weapon) {
                if (weapon == boss) {
                    continue;
                }
                if (((state >> weapon) & 1) == 0) {
                    continue;
                }
                int damage = weapons[weapon][boss] - '0';
                best = max(best, damage);
            }

            int newState = state | (1 << boss);

            int health = bosses[boss];
            int newShots = shots + (health / best);
            if (health % best != 0) {
                ++newShots;
            }

            nodes.push(Node(newState, newShots));
        }
    }

    return 0;
}
