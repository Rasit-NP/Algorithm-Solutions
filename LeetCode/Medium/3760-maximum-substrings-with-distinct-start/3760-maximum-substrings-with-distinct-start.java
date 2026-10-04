import java.util.Set;
import java.util.HashSet;

class Solution {
    public int maxDistinct(String s) {
        int n = s.length();

        Set<Character> charSet = new HashSet<>();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);

            charSet.add(c);
        }

        return charSet.size();
    }
}