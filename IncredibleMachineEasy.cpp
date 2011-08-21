#include <vector>
#include <string>
using namespace std;

double gravitationalAcceleration(vector<int> const &height,
                                 int T) {
    double sum = 0;
    for (int i = 0; i != height.size(); ++i)
        sum += sqrt(height[i]);
    double t = T/sum; 
    return 2/(t*t);
}
