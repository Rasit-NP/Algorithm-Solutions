class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] maximums = new int[n];

        int res = 0;

        maximums[n-1] = prices[n-1];

        for (int i=n-2; i>=0; --i){
            maximums[i] = Math.max(prices[i], maximums[i+1]);
        }

        for (int i=0; i<n-1; ++i){
            res = Math.max(res, maximums[i+1] - prices[i]);
        }

        return res;
    }
}