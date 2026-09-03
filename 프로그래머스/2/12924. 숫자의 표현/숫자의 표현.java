class Solution {
    public int solution(int n) {
        int res = 0;
        
        int l = 1, r = 1;
        int nowSum = 1;
        
        while (r <= n){
            if (nowSum == n){
                ++res;
            }
            if (nowSum <= n){
                nowSum += (++r);
            }
            else {
                nowSum -= (l++);
            }
        }
        
        return res;
    }
}