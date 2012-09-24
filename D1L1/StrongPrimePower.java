public class StrongPrimePower {
    public static boolean isPrime(int n) {
        for (int i = 2; (i * i) <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    public long naturalPow(int p, int q) {
        if (q == 1) {
            return p;
        }
        if (q == 0) {
            return 1;
        }
        long sqrt = naturalPow(p, q / 2);
        return sqrt * sqrt * naturalPow(p, q % 2);
    }
    public int[] pair(int p, int q) {
        int[] ret = new int[2];
        ret[0] = p; ret[1] = q;
        return ret;
    }
    public int[] baseAndExponent(String number) {
        Long n = Long.parseLong(number);
        for (int q = 2; q < 60; ++q) {
            double pp = Math.pow((double) n, 1.0 / q);
            int p = (int) Math.round(pp);
            if (isPrime(p) && naturalPow(p, q) == n) {
                return pair(p, q);
            }            
        }
        return new int[0];
    }
}