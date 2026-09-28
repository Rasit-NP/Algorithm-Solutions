import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;
import java.util.HashSet;

class Solution {

    char[] s;
    int pos;
    int n;
    public List<String> braceExpansionII(String expression) {
        pos = 0;
        n = expression.length();
        s = expression.toCharArray();

        List<String> res = new ArrayList<>(parseExpr());

        return res;
    }

    private Set<String> parseExpr(){
        Set<String> res = new TreeSet<>(parseTerm());

        while (pos < n && s[pos] == ','){
            ++pos;
            res.addAll(parseTerm());
        }

        return res;
    }

    private Set<String> parseTerm(){
        Set<String> res = new HashSet<>();
        res.add(new String());

        while (pos < n && (Character.isLetter(s[pos]) || s[pos] == '{')){
            Set<String> factor = parseFactor();
            Set<String> next = new HashSet<>();
            for (String a : res){
                for (String b : factor){
                    next.add(a + b);
                }
            }

            res = next;
        }
        return res;
    }

    private Set<String> parseFactor(){
        char c = s[pos];
        if (Character.isLetter(c)){
            pos++;
            return Set.of(String.valueOf(c));
        }
        pos++;
        Set<String> res = parseExpr();
        pos++;
        return res;
    }
}