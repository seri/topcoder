import java.util.Arrays;

class Date implements Comparable {
    private int day, month;
    public Date(String str) {
        String[] parts = str.split("/");
        int x = Integer.parseInt(parts[0]);
        int y = Integer.parseInt(parts[1]);
        if (x > y) {
            day = x; month = y;
        }
        else {
            day = y; month = x;
        }
    }

    public int getDay() {
        return day;
    }
    public int getMonth() {
        return month;
    }
    public void swap() {
        int temp = day; day = month; month = temp;
    }

    public int compareTo(Object o) {
        Date other = (Date) o;
        if (month < other.month) {
            return -1;
        }
        if (month == other.month) {
            if (day < other.day) {
                return -1;
            }
            if (day == other.day) {
                return 0;
            }
            return 1;
        }
        return 1;
    }

    private static String normalize(int n) {
        StringBuffer sb = new StringBuffer();
        if (n < 10) {
            sb.append('0');
        }
        sb.append(n);
        return sb.toString();
    }
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append(normalize(month));
        sb.append('/');
        sb.append(normalize(day));
        return sb.toString();
    }
}

public class DateFormat {
    public String join(String[] a) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < a.length; ++i) {
            sb.append(a[i]);
        }
        return sb.toString();
    }
    public String fromEuropeanToUs(String[] dateList) {
        String[] tokens = join(dateList).split(" ");
        
        Date[] dates = new Date[tokens.length];
        dates[0] = new Date(tokens[0]);

        for (int i = 1; i < tokens.length; ++i) {
            dates[i] = new Date(tokens[i]);
            if (dates[i].compareTo(dates[i - 1]) <= 0) {
                if (dates[i].getDay() > 12) {
                    return "";   
                }
                dates[i].swap();
                if (dates[i].compareTo(dates[i - 1]) <= 0) {
                    return "";
                }
            }
        }
        
        StringBuffer sb = new StringBuffer();
        sb.append(dates[0]).toString();
        for (int i = 1; i < dates.length; ++i) {
            sb.append(' ');
            sb.append(dates[i].toString());
        }
        return sb.toString();
    }
}