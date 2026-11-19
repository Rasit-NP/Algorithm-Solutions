class Solution {
    public char findTheDifference(String s, String t) {
        int n = s.length();

        int[] cnt = new int[26];

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);

            ++cnt[c-'a'];
        }

        for (int i=0; i<=n; ++i){
            char c = t.charAt(i);

            --cnt[c-'a'];
        }

        for (char c='a'; c<='z'; ++c){
            if (cnt[c-'a'] < 0){
                return c;
            }
        }

        return ' ';
    }
}