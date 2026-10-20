import java.util.Set;
import java.util.HashSet;

class Solution {
    public int sortableIntegers(int[] nums) {
        int n = nums.length;

        Set<Integer> set = getFactors(n);
        int res = 0;

        for (Integer f : set){
            boolean able = true;
            int befMax = 0;
            for (int seg=0; seg<n/f; ++seg){
                int localMin = nums[seg*f];
                int localMax = nums[seg*f];
                int bef = nums[seg*f];
                boolean isFall = false;
                for (int i=1; i<f; ++i){
                    int num = nums[seg*f + i];
                    localMin = Math.min(localMin, num);
                    localMax = Math.max(localMax, num);

                    if (num < bef && !isFall)
                        isFall = true;
                    else if (num < bef && isFall){
                        able = false;
                        break;
                    }
                    bef = num;
                }
                if (nums[seg*f] < nums[seg*f + f-1]){
                    if (isFall)
                        able = false;
                    else
                        isFall = true;
                }
                if (seg > 0 && befMax > localMin){
                    able = false;
                }
                befMax = localMax;
                if (!able)
                    break;
            }
            if (able)
                System.out.println(f);
            res += (able ? f : 0);
        }

        return res;
    }

    private Set<Integer> getFactors(int x){
        Set<Integer> set = new HashSet<>();

        for (int i=1; i*i<=x; ++i){
            if (x % i == 0){
                set.add(i);
                set.add(x/i);
            }
        }

        return set;
    }
}