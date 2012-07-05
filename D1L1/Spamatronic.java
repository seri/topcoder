import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class Spamatronic {
    public void tokenize(Set<String> tokens, String source) {
        String[] parts = source.split("[^a-zA-Z]");
        for (int i = 0; i < parts.length; ++i) {
            if (!parts[i].isEmpty()) {
                tokens.add(parts[i].toLowerCase());
            }
        }
    }
    public boolean isSpam(Set<String> spams, Set<String> tokens) {
        int count = 0;
        Iterator<String> it = tokens.iterator();
        while (it.hasNext()) {
            if (spams.contains(it.next())) {
                ++count;
            }
        }
        return (count * 4) >= (tokens.size() * 3);
    }    
    public int[] filter(String[] knownSpam,
                        String[] newMail) {
        Set<String> spams = new HashSet<String>();
        for (int i = 0; i < knownSpam.length; ++i) {
            tokenize(spams, knownSpam[i]);
        }

        List<Integer> indexes = new ArrayList<Integer>();
        for (int i = 0; i < newMail.length; ++i) {
            Set<String> tokens = new HashSet<String>();
            tokenize(tokens, newMail[i]);
            if (isSpam(spams, tokens)) {
                Iterator<String> it = tokens.iterator();
                while (it.hasNext()) {
                    spams.add(it.next());
                }
            }
            else {
                indexes.add(i);
            }
        }

        int[] ret = new int[indexes.size()];
        for (int i = 0; i < indexes.size(); ++i) {
            ret[i] = indexes.get(i).intValue();
        }
        return ret;
    }
}