int countOpponents(int P, int K) {
	int lower = 3 * K * P / (K + 9);
	int upper = 3 * K * (P + 4) / (K + 9);
	for (int N = lower; N <= upper; ++N) {
		if (3 * (N / K) + N / 3 == P) {
			return N;
		}
	}
    return -1;
}
