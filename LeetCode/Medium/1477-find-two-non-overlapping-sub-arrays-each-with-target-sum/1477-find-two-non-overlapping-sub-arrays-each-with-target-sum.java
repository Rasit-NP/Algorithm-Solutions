class Solution {

    private final int MAX = 1000000;
    private int[] prefix, suffix;

    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int l = 0, r = 0;
        int val = arr[0];

        prefix = new int[n];
        suffix = new int[n];
        Arrays.fill(prefix, MAX);
        Arrays.fill(suffix, MAX);

        while (r < n){
            if (val == target){
                if (r == 0)
                    prefix[0] = 1;
                else
                    prefix[r] = Math.min(r - l + 1, prefix[r-1]);
            }
            else if (r > 0){
                prefix[r] = prefix[r-1];
            }
            if (l == r || val <= target){
                ++r;
                if (r >= n)
                    break;
                val += arr[r];
            }
            else if (val > target){
                val -= arr[l++];
            }
        }

        l = n-1;
        r = n-1;
        val = arr[n-1];
        
        while (l >= 0){
            if (val == target){
                if (l == n-1)
                    suffix[n-1] = 1;
                else
                    suffix[l] = Math.min(r - l + 1, suffix[l+1]);
            }
            else if (l < n-1){
                suffix[l] = suffix[l+1];
            }
            if (l == r || val <= target){
                --l;
                if (l < 0)
                    break;
                val += arr[l];
            }
            else if (val > target){
                val -= arr[r--];
            }
        }

        int res = MAX;
        for (int i=0; i<n-1; ++i){
            if (prefix[i] != MAX && suffix[i+1] != MAX){
                res = Math.min(res, prefix[i] + suffix[i+1]);
            }
        }

        return res != MAX ? res : -1;
    }
}