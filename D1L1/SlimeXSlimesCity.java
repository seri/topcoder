import java.util.Arrays;

public class SlimeXSlimesCity {
    public int merge(int[] a) {
        Arrays.sort(a); 
        int n = a.length, 
            top = a[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            int sum = a[i];
            for (int j = 0; sum < top; ++j) {
                if (j == i) continue;
                if (sum >= a[j]) sum += a[j];
                            else break;
            }
            if (sum >= top) return n - i;
        }
        return 1;
    }
}
