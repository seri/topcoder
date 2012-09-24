public class MovieSeating {
    public long perms(int n, int k) {
        if (n < k) {
            return 0;
        }
        long ret = 1;
        for (int i = n; i > n - k; --i) {
            ret *= i;
        }
        return ret;
    }
    public long getSeatings(int k,
                            String[] hall) {
        long ret = 0;
        for (int i = 0; i < hall.length; ++i) {
            int n = 0;
            for (int j = 0; j < hall[i].length(); ++j) {
                if (hall[i].charAt(j) == '.') {
                    ++n;
                }
            }
            ret += perms(n, k);
        }
        for (int i = 0; i < hall[0].length(); ++i) {
            int n = 0;
            for (int j = 0; j < hall.length; ++j) {
                if (hall[j].charAt(i) == '.') {
                    ++n;
                }
            }
            ret += perms(n, k);
        }
        return k == 1 ? (ret / 2) : ret;
    }
}