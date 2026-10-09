class Solution {
    public int minInsertions(String s) {
        int now = 0;
        int res = 0;
        int n = s.length();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);

            if (c == '('){
                if (now < 0){
                    res += Math.abs(now)/2 + 2*(now&1);
                    now = 0;
                }
                else if ((now&1) == 1){
                    res += 1;
                    --now;
                }
                now += 2;
            }
            else {
                --now;
            }
        }

        if (now < 0){
            res += Math.abs(now)/2 + 2*(now&1);
        }
        else {
            res += now;
        }

        return res;
    }
}