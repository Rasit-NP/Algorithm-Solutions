class Solution {
    public String[] createGrid(int n, int m) {
        String[] res = new String[n];

        for (int i=0; i<n; ++i){
            char[] now = new char[m];
            if (i == 0){
                Arrays.fill(now, '.');
            }
            else {
                Arrays.fill(now, '#');
                now[m-1] = '.';
            }
            res[i] = new String(now);
        }

        return res;
    }
}