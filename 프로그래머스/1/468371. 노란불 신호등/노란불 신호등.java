class Solution {
    public int solution(int[][] signals) {
        int n = signals.length;
        int[] sums = new int[n];
        
        for (int i=0; i<n; i++){
            sums[i] = signals[i][0] + signals[i][1] + signals[i][2];
        }
        
        for (int t=0; t<=3200000; t++){
            boolean isAble = true;
            for (int i=0; i<n; i++){
                int mod = t % sums[i];
                if (mod >= signals[i][0] && mod < signals[i][0] + signals[i][1]){
                    continue;
                }
                else {
                    isAble = false;
                    break;
                }
            }
            if (isAble){
                return t+1;
            }
        }
        
        return -1;
    }
}