class Solution {
    public String digitSum(String s, int k) {
        int n = s.length();
        while (n > k){
            int now = 0;
            String str = "";
            for (int i=0; i<n; ++i){
                int num = s.charAt(i) - '0';
                now += num;
                if (i%k == k-1 || i == n-1){
                    str += String.valueOf(now);
                    now = 0;
                }
            }
            s = str;
            n = s.length();
        }
        return s;
    }
}