#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> parse(string hand) {
    vector<string> cards(3);
    istringstream iss(hand); iss >> cards[0] >> cards[1] >> cards[2];
    return cards;
}

int convert(string card) {
    switch (card[0]) {
        case 'A': return 11;
        case 'J': 
        case 'Q':
        case 'K': return 10;
        default : int ret; istringstream(card) >> ret; return ret;
    }
}

int value(vector<string> const &cards) {
    if (cards[0] == cards[1] && cards[1] == cards[2]) {
        return 61;
    }    
    vector<int> a(3); 
    transform(begin(cards), end(cards), begin(a), convert);
    int sum = accumulate(begin(a), end(a), 0);
    return sum == 32 ? 44 : (2 * sum);
}

int findWinner(vector<string> const &hands) {
    int best = 0, ret = 0;
    for (int i = 0; i != hands.size(); ++i) {
        int cur = value(parse(hands[i]));
        if (cur > best) {
            best = cur;
            ret = i;
        }
    }
    return ret;
}
