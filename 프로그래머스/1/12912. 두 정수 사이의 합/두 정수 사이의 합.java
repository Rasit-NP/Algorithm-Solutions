class Solution {
    public long solution(int a, int b) {
        long res = ((long)a + b) * (a > b ? a - b + 1 : b - a + 1) / 2;
        
        return res;
    }
}