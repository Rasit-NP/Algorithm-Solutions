import java.util.Arrays;

class Solution {
    public int solution(int[] A, int[] B) {
        int res = 0;
        int n = A.length;
        
        Arrays.sort(A);
        Arrays.sort(B);
        
        for (int i=0; i<n; i++){
            res += A[i] * B[n-i-1];
        }
        
        return res;
    }
}