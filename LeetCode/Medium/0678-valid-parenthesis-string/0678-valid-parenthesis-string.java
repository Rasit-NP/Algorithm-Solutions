class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        int nowVal = 0;
        int starCount = 0;

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);
            if (c == '('){
                ++nowVal;
            }
            else if (c == ')'){
                --nowVal;
            }
            else {
                ++starCount;
            }
            if (nowVal + starCount < 0){
                return false;
            }
        }

        nowVal = 0;
        starCount = 0;

        for (int i=n-1; i>=0; --i){
            char c = s.charAt(i);
            if (c == '('){
                --nowVal;
            }
            else if (c == ')'){
                ++nowVal;
            }
            else {
                ++starCount;
            }
            if (nowVal + starCount < 0){
                return false;
            }
        }

        return Math.abs(nowVal) <= starCount;
    }
}