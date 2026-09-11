import java.util.HashSet;

class Solution {

    public int totalNumbers(int[] digits) {
        int n = digits.length;
        int res = 0;
        Set<Integer> set = new HashSet<>();

        for (int i=0; i<n; ++i){
            if (digits[i] == 0)
                continue;
            for (int j=0; j<n; ++j){
                if (i == j)
                    continue;
                for (int k=0; k<n; ++k){
                    if (i == k || j == k)
                        continue;
                    int num = 100*digits[i] + 10*digits[j] + digits[k];
                    if ((num&1) == 0 && !set.contains(num)){
                        ++res;
                        set.add(num);
                    }
                }
            }
        }

        return res;
    }
}