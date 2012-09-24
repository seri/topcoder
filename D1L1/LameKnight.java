public class LameKnight {
    public int maxCells(int height,
                        int width) {
        if (height == 1 || width == 1) {
            return 1;
        }
        if (height == 2) {
            return Math.min(4, (width + 1)/2);
        }
        if (width >= 7) {
            return width - 2;            
        }
        return Math.min(4, width);
    }
}