import java.util.ArrayDeque;

class Solution {

    private int n;
    private int i = 0;
    private String s;
    private int[][] score;

    private int parse(){
        int res = 0;

        ArrayDeque<Character> stk = new ArrayDeque<>();
        stk.addLast(s.charAt(i++));

        while (stk.size() > 0){
            char c = s.charAt(i);
            if (c == '('){
                res += parse();
            }
            else {
                stk.removeLast();
            }
        }
        i++;

        return Math.max(2*res, 1);
    }

    public int scoreOfParentheses(String s) {
        this.s = s;
        n = s.length();

        score = new int[n][n];

        int res = 0;

        while (i < n){
            res += parse();
        }

        return res;
    }
}