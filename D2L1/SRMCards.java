import java.util.Arrays;

public class SRMCards {
    public int maxTurns(int[] cards) {
        Arrays.sort(cards); 
        int ret = 0, prev = 0;
        for (int i = 0; i < cards.length; ++i) {
            if (cards[i] != prev) {
                ++ret;
                prev = cards[i] + 1;
            }
        }
        return ret;
    }
}