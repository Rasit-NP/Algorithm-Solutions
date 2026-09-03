class Solution {
    public int solution(int n) {
        int a = 0, b = 1;
        for (int i=2; i<=n; i++){
            int tmp = a + b;
            tmp %= 1234567;
            a = b;
            b = tmp;
        }
        
        return b;
    }
}