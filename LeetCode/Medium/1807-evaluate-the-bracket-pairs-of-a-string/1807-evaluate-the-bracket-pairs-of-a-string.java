import java.util.Map;
import java.util.HashMap;

class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> map = new HashMap<>();

        for (List<String> know : knowledge){
            map.put(know.get(0), know.get(1));
        }

        int n = s.length();

        StringBuilder res = new StringBuilder();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);

            if (c != '(')
                res.append(c);
            else {
                ++i;
                String key = new String();
                while (s.charAt(i) != ')'){
                    key += s.charAt(i++);
                }
                res.append(map.getOrDefault(key, "?"));
            }
        }

        return res.toString();
    }
}