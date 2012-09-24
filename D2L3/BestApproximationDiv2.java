public class BestApproximationDiv2 {
    public String buildResult(int a, int b, int x) {
        StringBuffer sb = new StringBuffer();
        sb.append(a); sb.append('/'); sb.append(b);
        sb.append(" has "); sb.append(x); sb.append(" exact digits");
        return sb.toString();
    }
    public boolean satisfy(int a, int b, String s) {
        for (int i = 2; i < s.length(); ++i) {
            int d = s.charAt(i) - '0';
            a = 10 * a; 
            if ((a / b) != d) return false;
            a = a % b;
        }
        return true;
    }
    public String findFraction(int maxDen,
                               String number) {
        int reta = 0, retb = 1, retx = 1;
        int hi = number.length() - 1, lo = 2;
        while (lo <= hi) {
            int x = (lo + hi)/2;
            String sub = number.substring(0, x + 1);
            double y = Double.parseDouble(sub);
            boolean ok = false;
            for (int b = 1; b <= maxDen; ++b) {
                int a = (int) Math.round(y * b);
                if (satisfy(a, b, sub)) {
                    reta = a; retb = b; retx = x;
                    ok = true; break;
                }
            }
            if (ok) lo = x + 1; else hi = x - 1;
        }
        return buildResult(reta, retb, retx);
    }
}