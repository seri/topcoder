public class IncredibleMachineEasy {
    public double gravitationalAcceleration(int[] height,
                                            int T) {
        double sum = 0;
        for (int i = 0; i < height.length; ++i) {
            sum += Math.sqrt(2 * height[i]);
        }
        double ret = sum / T;
        return ret * ret;
    }
}