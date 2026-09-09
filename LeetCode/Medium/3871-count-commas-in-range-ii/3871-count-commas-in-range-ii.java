class Solution {
    public long countCommas(long n) {
        long res = 0;
        long cmp = 999;
        while (n > cmp){
            res += Math.max(0, n-cmp);
            cmp *= 1000;
            cmp += 999;
        }

        return res;
    }
}