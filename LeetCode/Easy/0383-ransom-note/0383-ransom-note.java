class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] cnt = new int[26];

        for (int i=0, lim = ransomNote.length(); i<lim; ++i){
            char c = ransomNote.charAt(i);

            ++cnt[c-'a'];
        }

        for (int i=0, lim = magazine.length(); i<lim; ++i){
            char c = magazine.charAt(i);

            --cnt[c-'a'];
        }

        for (int i=0; i<26; ++i){
            if (cnt[i] > 0)
                return false;
        }

        return true;
    }
}