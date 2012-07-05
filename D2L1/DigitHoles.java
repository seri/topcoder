public class DigitHoles {
    public int numHoles(int number) {
        String s = Integer.toString(number);
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            switch (s.charAt(i) - '0') {
                case 0:
                case 4:
                case 6:
                case 9:
                    ret += 1;
                    break;
                case 8:
                    ret += 2;
                    break;
            }
        }
        return ret;
    }
}