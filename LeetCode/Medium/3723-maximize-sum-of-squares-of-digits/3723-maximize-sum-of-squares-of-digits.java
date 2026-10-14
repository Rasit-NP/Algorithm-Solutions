class Solution {
    public String maxSumOfSquares(int num, int sum) {
        char[] res = new char[num];

        if (sum > num * 9)
            return "";

        for (int i=0; i<num; ++i){
            if (sum == 0){
                res[i] = '0';
                continue;
            }
            int val = Math.min(9, sum);
            
            res[i] = (char)('0' + val);
            sum -= val;
        }

        return new String(res);
    }
}