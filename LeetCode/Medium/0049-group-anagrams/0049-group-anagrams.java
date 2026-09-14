import java.util.HashMap;
import java.util.Arrays;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String str : strs){
            char[] cs = str.toCharArray();
            Arrays.sort(cs);
            String s = new String(cs);

            map.computeIfAbsent(s, k -> new ArrayList<>()).add(str);
        }

        return new ArrayList<>(map.values());
    }
}