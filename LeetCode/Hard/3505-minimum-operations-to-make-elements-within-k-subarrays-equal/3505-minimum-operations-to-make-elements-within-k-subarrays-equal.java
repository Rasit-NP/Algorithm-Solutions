import java.util.PriorityQueue;

class Solution {

    public long minOperations(int[] nums, int x, int k) {

        int n = nums.length;

        long[] cost = new long[n-x+1];

        PriorityQueue<Integer> left = new PriorityQueue<>((a, b) -> Integer.compare(nums[b], nums[a]));
        PriorityQueue<Integer> right = new PriorityQueue<>((a, b) -> Integer.compare(nums[a], nums[b]));
        boolean[] inLeft = new boolean[n];
        int sizeL = 0, sizeR = 0;
        long sumL = 0, sumR = 0;

        for (int i=0; i<n; ++i){
            int start = i-x+1;

            if (i >= x){
                int out = i-x;
                if (inLeft[out]){
                    --sizeL;
                    sumL -= nums[out];
                }
                else {
                    --sizeR;
                    sumR -= nums[out];
                }
            }

            left.add(i);
            inLeft[i] = true;
            ++sizeL;
            sumL += nums[i];

            prune(left, start);
            int t = left.poll();
            inLeft[t] = false;
            --sizeL;
            sumL -= nums[t];
            right.add(t);
            ++sizeR;
            sumR += nums[t];

            while (sizeL > sizeR+1){
                prune(left, start);
                int m = left.poll();
                inLeft[m] = false;
                --sizeL;
                sumL -= nums[m];
                right.add(m);
                ++sizeR;
                sumR += nums[m];
            }
            while (sizeL < sizeR){
                prune(right, start);
                int m = right.poll();
                inLeft[m] = true;
                --sizeR;
                sumR -= nums[m];
                left.add(m);
                ++sizeL;
                sumL += nums[m];
            }

            if (i >= x-1){
                prune(left, start);
                long v = nums[left.peek()];
                cost[start] = v*sizeL - sumL + sumR - v*sizeR;
            }
        }

        long[][] dp = new long[k+1][n];

        for (int l=1; l<=k; ++l){
            for (int i=x*l-1, j=i-(x-1); i<n; ++i, ++j){
                long res = (l == 1 ? 0 : dp[l-1][i-x]) + cost[j];

                if (i == x*l-1){
                    dp[l][i] = res;
                }
                else {
                    dp[l][i] = Math.min(res, dp[l][i-1]);
                }
            }
        }

        return dp[k][n-1];
    }

    private void prune(PriorityQueue<Integer> pq, int start){
        while (!pq.isEmpty() && pq.peek() < start){
            pq.poll();
        }
    }
}