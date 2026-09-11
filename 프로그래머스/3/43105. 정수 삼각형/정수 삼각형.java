import java.util.ArrayList;
import java.util.List;

class Solution {
    public int solution(int[][] triangle) {
        int n = triangle.length;
        List<List<Integer>> dp = new ArrayList<>(n);
        
        for (int i=0; i<n; ++i){
            dp.add(new ArrayList<>(i+1));
            for (int j=0; j<i+1; ++j){
                dp.get(i).add(triangle[i][j]);
            }
        }
        
        for (int i=n-2; i>=0; --i){
            for (int j=0; j<=i; ++j){
                dp.get(i).set(j, Math.max(dp.get(i+1).get(j), dp.get(i+1).get(j+1)) + dp.get(i).get(j));
            }
        }
        
        int answer = dp.get(0).get(0);
        return answer;
    }
}