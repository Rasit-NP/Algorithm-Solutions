class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        int maxAns = 0;
        int res = 0;

        int sum1 = 0, sum2 = 0;
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                sum1 += img1[i][j];
                sum2 += img2[i][j];
            }
        }

        maxAns = Math.min(sum1, sum2);

        for (int di=-n; di<n; ++di){
            for (int dj=-n; dj<n; ++dj){
                int cnt = 0;
                for (int i=0; i<n; ++i){
                    int ni = i + di;
                    if (ni < 0 || ni >= n)
                        continue;
                    for (int j=0; j<n; ++j){
                        int nj = j + dj;
                        if (nj < 0 || nj >= n)
                            continue;
                        
                        cnt += (img1[i][j] == 1 && img2[ni][nj] == 1 ? 1 : 0);
                    }
                }
                res = Math.max(res, cnt);
                if (res == maxAns)
                    return res;
            }
        }

        return res;
    }
}