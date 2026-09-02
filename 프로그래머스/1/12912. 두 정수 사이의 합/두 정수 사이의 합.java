class Solution {
    public long solution(int a, int b) {
        return solution((long) a, (long) b);
    }
    
    public long solution(long a, long b){
        return (a + b) * (a > b ? a - b + 1 : b - a + 1) / 2;
    }
}