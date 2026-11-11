class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long sum = 0;
        if (need1 > 0 && costBoth < cost1){
            sum += (long)costBoth * need1;
            need2 -= need1;
            need1 = 0;
        }
        if (need2 > 0 && costBoth < cost2){
            sum += (long)costBoth * need2;
            need1 -= need2;
            need2 = 0;
        }

        if (need1 > 0 && need2 > 0 && costBoth < (cost1 + cost2)){
            int need = Math.min(need1, need2);
            sum += (long)costBoth * need;
            need1 -= need;
            need2 -= need;
        }

        if (need1 > 0){
            sum += (long)cost1 * need1;
        }
        if (need2 > 0){
            sum += (long)cost2 * need2;
        }

        return sum;
    }
}