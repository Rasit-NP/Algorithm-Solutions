import java.util.Set;
import java.util.HashSet;

class Solution {

    public int[] countServers(int n, int[][] logs, int x, int[] queries) {

        int l = logs.length;
        int q = queries.length;

        int maxQuery = 0;

        for (int query : queries){
            maxQuery = Math.max(maxQuery, query);
        }
        ++maxQuery;

        int[] count = new int[n+1];
        int[] res = new int[maxQuery];
        int[] ans = new int[queries.length];
        int[][] sortedLogs = new int[2*l][2];
        
        Set<Integer> set = new HashSet<>();

        for (int i=0; i<l; ++i){
            int[] log = logs[i];

            sortedLogs[2*i][0] = log[1];
            sortedLogs[2*i][1] = log[0];
            sortedLogs[2*i+1][0] = log[1] + x + 1;
            sortedLogs[2*i+1][1] = -log[0];
        }

        Arrays.sort(sortedLogs, (a, b) -> a[0]-b[0]);

        for (int now = sortedLogs[0][0], logIdx = 0; now<maxQuery; ++now){
            while (logIdx < 2*l && sortedLogs[logIdx][0] <= now){
                int val = sortedLogs[logIdx][1];

                if (val > 0){
                    if (count[val]++ == 0)
                        set.add(val);
                }
                else {
                    if (--count[-val] == 0)
                        set.remove(-val);
                }
                ++logIdx;
            }

            res[now] = set.size();
        }

        for (int i=0; i<q; ++i){
            int query = queries[i];

            ans[i] = n - res[query];
        }

        return ans;
    }
}