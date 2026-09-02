class Solution {
    public int solution(String s) {
        int res = 0;
        boolean sign;
        if (s.charAt(0) >= '0' && s.charAt(0) <= '9'){
            return Integer.parseInt(s);
        }
        else if (s.charAt(0) == '+')
            sign = true;
        else
            sign = false;
        
        for (int i=s.length()-1, base=1; i>0; --i, base *= 10){
            res += (s.charAt(i) - '0') * base;
        }
        
        return sign ? res : -res;
    }
}