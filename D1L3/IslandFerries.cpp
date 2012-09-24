#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int F, L;
bool edge[10][40][40];
int cost[10][40];
bool done[40][1 << 10];
int reachable;

struct Node {
    int at;
    int spent;   
    int has;
};
bool operator<(Node const &p, Node const &q) {
    return p.spent > q.spent;
}

int countBits(int mask) {
    int ret = 0;
    while (mask != 0) {
        ret += (mask & 1);
        mask >>= 1;
    }
    return ret;
}

void getLegs(vector<string> const &legs) {
    F = legs.size();
    memset(edge, false, sizeof(edge));
    bool canReach[40]; memset(canReach, false, sizeof(canReach));
    for (int f = 0; f != F; ++f) {
        istringstream iss(legs[f]);
        while (true) {
            int src, dst;
            iss >> src;
            if (!iss.good()) {
                break;
            }
            iss.ignore(1);
            iss >> dst;
            edge[f][src][dst] = true;
            canReach[dst] = true;
        }
    }  
    
    reachable = 0;
    for (int i = 0; i != 40; ++i) {
        if (canReach[i]) {
            ++reachable;
        }
    }
}

void getPrices(vector<string> const &prices) {
    L = prices.size();
    for (int l = 0; l != L; ++l) {
        istringstream iss(prices[l]);
        for (int f = 0; f != F; ++f) {
            iss >> cost[f][l];
        }
    }
}

vector<int> costs(vector<string> const &legs,
                  vector<string> const &prices) {
    getLegs(legs);
    getPrices(prices);
    vector<int> ret(L - 1, -1);

    priority_queue<Node> nodes;
    Node init = {0, 0, 0};
    nodes.push(init);
    
    memset(done, false, sizeof(done));
    int found = 0;

    while (!nodes.empty()) {
        Node node = nodes.top(); nodes.pop();
        int at = node.at, spent = node.spent, has = node.has;
        
        if (at != 0) {
            if (ret[at - 1] == -1) {
                ret[at - 1] = spent;
                if (++found == reachable) {
                    break;
                }
            }
        }
        
        if (done[at][has]) {
            continue;
        }
        done[at][has] = true;

        if (has != 0) {
            for (int to = 0; to != L; ++to) {
                if (to == at) {
                    continue;
                }
                for (int f = 0; f != F; ++f) {
                    if ((has & (1 << f)) && edge[f][at][to]) {
                        Node next = {to, spent, (has ^ (1 << f))};
                        nodes.push(next);
                    }
                }
            }
        }

        if (countBits(has) < 3) {
            for (int f = 0; f != F; ++f) {
                if ((has & (1 << f)) == 0) {
                    Node next = {at, spent + cost[f][at], (has | (1 << f))};
                    nodes.push(next);
                }
            }
        }
    }
    
    return ret;
}
