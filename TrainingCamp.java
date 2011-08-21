public class TrainingCamp {
    String[] determineSolvers(String[] a,
                              String[] b) {
        int n = a.length, m = a[0].length(), p = b.length;
        String[] ret = new String[n];
        for (int i = 0; i < n; ++i) {
            StringBuffer sb = new StringBuffer();
            for (int j = 0; j < p; ++j) {
                char c = 'X';
                for (int k = 0; k < m; ++k) {
                    if (a[i].charAt(k) == '-' && 
                        b[j].charAt(k) == 'X') {
                        c = '-';
                        break;
                    }
                }
                sb.append(c);
            }
            ret[i] = sb.toString();
        }
        return ret;
    }
}