import java.util.List;
import java.util.ArrayDeque;
import java.util.ArrayList;

class Solution {
    public String reverseParentheses(String s) {

        int n = s.length();
        ArrayDeque<Character> stack = new ArrayDeque<>();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);
            if (c != ')'){
                stack.addLast(c);
            }
            else {
                List<Character> list = new ArrayList<>();
                while (stack.peekLast() != '('){
                    list.add(stack.peekLast());
                    stack.removeLast();
                }
                stack.removeLast();

                int m = list.size();
                for (int j=0; j<m; ++j){
                    stack.addLast(list.get(j));
                }
            }
        }

        StringBuilder res = new StringBuilder();

        while (stack.size() > 0){
            res.append(stack.peekFirst());
            stack.removeFirst();
        }

        return res.toString();
    }
}