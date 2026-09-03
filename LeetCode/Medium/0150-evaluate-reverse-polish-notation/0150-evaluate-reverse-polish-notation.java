import java.util.ArrayDeque;

class Solution {
    public int evalRPN(String[] tokens) {
        int n = tokens.length;

        ArrayDeque<Integer> dq = new ArrayDeque<>();

        for (int i=0; i<n; i++){
            String token = tokens[i];
            if (token.equals("+")){
                int b = dq.peek();  dq.pop();
                int a = dq.peek();  dq.pop();
                dq.push(a+b);
            }
            else if (token.equals("-")){
                int b = dq.peek();  dq.pop();
                int a = dq.peek();  dq.pop();
                dq.push(a-b);
            }
            else if (token.equals("*")){
                int b = dq.peek();  dq.pop();
                int a = dq.peek();  dq.pop();
                dq.push(a*b);
            }
            else if (token.equals("/")){
                int b = dq.peek();  dq.pop();
                int a = dq.peek();  dq.pop();
                dq.push(a/b);
            }
            else {
                int num = Integer.parseInt(token);
                dq.push(num);
            }
        }

        return dq.pop();
    }
}