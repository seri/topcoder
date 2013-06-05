#include <cmath>

int countPairs(int N, int M) {
	int ret = 0;
	for (int A = 1; A <= N; ++A) {
		/* 
			We need to find the number of B such that A * B is a perfect square.
			Now assume:
			- sqA is the largest perfect square such that A divides sqA
			- sqB is the largest perfect square such that A divides sqB
			- a = A/sqA
			- b = B/sqB
			We can easily find sqA and then a.
			Since a * b has to be a perfect square, we can deduce that b = a.
		*/
		int sqA = 1;
		for (int i = 2; ; ++i) {
			int ii = i * i;
			if (ii > A) {
				break;
			}
			if (A % ii == 0) {
				sqA = ii;
			}
		}
		int a = A/sqA;
		ret += floor(sqrt(M/a));
	}
    return ret;
}
