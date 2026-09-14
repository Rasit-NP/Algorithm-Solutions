import java.util.HashMap;

class Solution {
    public boolean isAnagram(String s, String t) {
        int ns = s.length(), nt = t.length();

        if (ns != nt)
            return false;

        Map<Character, Integer> cnt = new HashMap<>();
        
        for (int i=0; i<ns; ++i){
            char cs = s.charAt(i);
            char ts = t.charAt(i);

            cnt.put(cs, cnt.getOrDefault(cs, 0) + 1);
            cnt.put(ts, cnt.getOrDefault(ts, 0) - 1);
        }

        for (Character c : cnt.keySet()){
            if (cnt.get(c) != 0){
                return false;
            }
        }

        return true;
    }
}