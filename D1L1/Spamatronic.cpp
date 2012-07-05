#include <cctype>
#include <vector>
#include <string>
#include <set>
#include <sstream>
using namespace std;

void tokenize(set<string> &tokens, string const &st) {
    ostringstream oss;
    for (int i = 0; i != st.size(); ++i)
        if (isalpha(st[i]))
            oss << toupper(st[i]);
        else if (!oss.str().empty()) {
            tokens.insert(oss.str());
            oss.str("");
        }
    if (!oss.str().empty()) 
        tokens.insert(oss.str());
} 
vector<int> filter(vector<string> const &knownSpam,
                   vector<string> const &newMail) {
    vector<int> ret; set<string> spams;
    for (auto it = knownSpam.begin(); it != knownSpam.end(); ++it)
        tokenize(spams, *it);
    for (int i = 0; i != newMail.size(); ++i) {
        set<string> tokens; tokenize(tokens, newMail[i]); int k = 0;
        for (auto it = tokens.begin(); it != tokens.end(); ++it)
            if (spams.find(*it) != spams.end()) 
                ++k;
        if (tokens.size() * 3 <= k * 4) 
            for (auto it = tokens.begin(); it != tokens.end(); ++it) 
                spams.insert(*it);
        else ret.push_back(i);
    }
    return ret;
}
