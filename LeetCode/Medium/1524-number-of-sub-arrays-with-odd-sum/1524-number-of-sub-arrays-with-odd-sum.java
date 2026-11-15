class Solution {
    private static final int MAX = 1_000_000_007;
    public int numOfSubarrays(int[] arr) {
        int odds = 0;
        int evens = 0;

        int res = 0;

        for (int num : arr){
            int newOdd;
            int newEven;
            if ((num&1) == 1){
                newOdd = evens + 1;
                newEven = odds;
            }
            else {
                newOdd = odds;
                newEven = evens + 1;
            }
            odds = newOdd;
            evens = newEven;

            res += odds;
            if (res >= MAX)
                res -= MAX;
        }

        return res;
    }
}