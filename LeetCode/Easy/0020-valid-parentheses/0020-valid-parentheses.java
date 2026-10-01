import java.util.ArrayDeque;

class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        ArrayDeque<Character> stk = new ArrayDeque<>();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);

            if (stk.size() == 0 || c == '(' || c == '{' || c == '['){
                stk.addLast(c);
            }
            else if (c == ')' && stk.peekLast() == '('){
                stk.removeLast();
            }
            else if (c == ']' && stk.peekLast() == '['){
                stk.removeLast();
            }
            else if (c == '}' && stk.peekLast() == '{'){
                stk.removeLast();
            }
            else {
                stk.addLast(c);
            }
        }

        return stk.size() == 0;
    }
}