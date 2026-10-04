class Solution {
    public int minPartitions(String n) {
        int res = 0;
        int sz = n.length();

        for (int i=0; i<sz; ++i){
            res = Math.max(res, n.charAt(i)-'0');
        }

        return res;
    }
}