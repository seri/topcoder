public class GravityBomb {
    String[] aftermath(String[] board) {
        int w = board[0].length(), 
            h = board.length;
        
        int[] depths = new int[w]; int min = 51;
        for (int x = 0; x < w; ++x) {
            depths[x] = 0;
            for (int y = 0; y < h; ++y) 
                if (board[y].charAt(x) == 'X') ++depths[x];
            if (depths[x] < min) min = depths[x];
        }
        for (int i = 0; i < w; ++i)
            depths[i] = h - (depths[i] - min);
        
        char[][] temp = new char[h][w];
        for (int x = 0; x < w; ++x) {
            for (int y = 0; y < depths[x]; ++y)
                temp[y][x] = '.';
            for (int y = depths[x]; y < h; ++y)
                temp[y][x] = 'X';
        }

        String[] ret = new String[h];
        for (int i = 0; i < h; ++i)
            ret[i] = new String(temp[i]);
        return ret;
    }
}