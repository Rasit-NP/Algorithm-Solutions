import java.util.List;

class Solution {

    private final int MOD = 1_000_000_007;

    public int maxSum(List<Integer> nums, int k) {
        int n = nums.size();
        
        int[] bitCount = new int[31];

        for (int i=0; i<n; ++i){
            int num = nums.get(i);

            for (int bit=0; bit<31; ++bit){
                bitCount[bit] += ((num & (1 << bit)) > 0 ? 1 : 0);
            }
        }

        long res = 0;

        for (int i=0; i<k; ++i){
            long val = 0;
            for (int bit=0; bit<31; ++bit){
                if (bitCount[bit] > 0){
                    val += 1 << bit;
                    --bitCount[bit];
                }
            }

            res += (val * val) % MOD;
            if (res >= MOD)
                res -= MOD;
        }

        return (int)res;
    }
}