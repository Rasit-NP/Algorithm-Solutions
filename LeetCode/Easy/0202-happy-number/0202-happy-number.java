import java.util.Set;
import java.util.HashSet;

class Solution {
    public boolean isHappy(int n) {
        Set set = new HashSet<>();

        set.add(n);

        while (true){
            n = get(n);
            if (n == 1)
                return true;
            else if (set.contains(n)){
                return false;
            }
            else {
                set.add(n);
            }
        }
    }

    private int get(int x){
        int res = 0;
        while (x > 0){
            int v = x % 10;
            x /= 10;

            res += v * v;
        }

        return res;
    }
}