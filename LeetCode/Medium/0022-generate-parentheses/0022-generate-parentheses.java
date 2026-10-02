import java.util.ArrayList;

class Solution {

    private int n;
    private final List<String> res = new ArrayList<>();
    private final StringBuilder sb = new StringBuilder();

    private void backtrack(int sz, int now, int cnt){
        if (sz == 2*n){
            res.add(sb.toString());
            return;
        }
        if (cnt < n){
            sb.append('(');
            backtrack(sz+1, now+1, cnt+1);
            sb.deleteCharAt(sz);
        }
        if (now > 0){
            sb.append(')');
            backtrack(sz+1, now-1, cnt);
            sb.deleteCharAt(sz);
        }
    }

    public List<String> generateParenthesis(int n) {
        this.n = n;

        backtrack(0, 0, 0);

        return res;
    }
}