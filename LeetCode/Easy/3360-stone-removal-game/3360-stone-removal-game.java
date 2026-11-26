class Solution {
    public boolean canAliceWin(int n) {
        boolean res = false;
        int now = 10;

        while (n >= 0){
            if (n >= now){
                n -= now--;
                res = !res;
            }
            else {
                return res;
            }
        }

        return true;
    }
}