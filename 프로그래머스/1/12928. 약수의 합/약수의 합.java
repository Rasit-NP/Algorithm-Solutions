class Solution {
    public int solution(int n) {
        int res = 0;
        for (int i=1; i<=n; i++){
            res += (n%i == 0 ? i : 0);
        }
        
        return res;
    }
}