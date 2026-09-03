import java.util.ArrayDeque;

class Solution {
    public int solution(String s) {
        int n = s.length();
        ArrayDeque<Character> dq = new ArrayDeque<>();
        
        for (int i=0; i<n; i++){
            char c = s.charAt(i);
            if (dq.isEmpty()){
                dq.push(c);
                continue;
            }
            if (c == dq.peek()){
                dq.pop();
            }
            else {
                dq.push(c);
            }
        }
        
        return dq.isEmpty() ? 1 : 0;
    }
}