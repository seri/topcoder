public class LuckyRemainder {
    public int pow2mod9(int n) {
        switch (n % 6) {
            case 0 : return 1;
            case 1 : return 2;
            case 2 : return 4;
            case 3 : return 8;
            case 4 : return 7;
            case 5 : return 5;
        }
        return 0;
    }
    public int getLuckyRemainder(String X) {
        int sum = 0;
        for (int i = 0; i < X.length(); ++i) {
            sum += X.charAt(i) - '0';
        }
        sum %= 9;
        return (sum * pow2mod9(X.length() - 1)) % 9;
    }
}