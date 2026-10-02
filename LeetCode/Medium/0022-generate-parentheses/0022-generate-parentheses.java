import java.util.ArrayList;

class Solution {
    public List<String> generateParenthesis(int n) {
        int lim = 1 << (2*n);

        List<String> res = new ArrayList<>();

        for (int i=0; i<lim; ++i){
            int now = 0;
            StringBuilder sb = new StringBuilder();

            for (int bit=0; bit<2*n; ++bit) {
                int val = (i >> bit) & 1;
                if (val == 1){
                    sb.append('(');
                    ++now;
                }
                else {
                    sb.append(')');
                    --now;
                }

                if (now < 0)
                    break;
            }
            
            if (now == 0) {
                res.addLast(sb.toString());
            }
        }

        return res;
    }
}