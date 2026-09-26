import java.util.Map;
import java.util.HashMap;

class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> map = new HashMap<>();

        for (List<String> know : knowledge){
            String key = know.get(0);
            String value = know.get(1);

            map.put(key, value);
        }

        int n = s.length();

        String res = new String();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);

            if (c != '(')
                res += c;
            else {
                ++i;
                String key = new String();
                while (s.charAt(i) != ')'){
                    key += s.charAt(i++);
                }
                res += map.getOrDefault(key, "?");
            }
        }

        return res;
    }
}