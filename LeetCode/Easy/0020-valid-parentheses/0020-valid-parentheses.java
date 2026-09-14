import java.util.ArrayDeque;

class Solution {
    public boolean isValid(String s) {
        char[] list = s.toCharArray();
        ArrayDeque<Character> stk = new ArrayDeque<>();

        for (char c : list){
            if (stk.size() == 0){
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

        return stk.isEmpty();
    }
}