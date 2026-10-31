import java.util.List;
import java.util.ArrayList;
import java.util.ArrayDeque;

class Solution {

    private static final int LOG = 16;

    private int n;
    private char[] s;
    private List<List<Integer>> edges;

    private int[] tin, tout, depth;
    private int[][] up;

    private int[] tag;

    public List<Boolean> palindromePath(int n, int[][] es, String ss, String[] queries) {        
        init(n, es, ss);
        List<Boolean> res = new ArrayList<>();

        for (String query : queries){
            String[] q = query.split(" ");

            if (query.charAt(0) == 'q'){
                int u = Integer.parseInt(q[1]);
                int v = Integer.parseInt(q[2]);

                int w = lca(u, v);
                int mask = pointQuery(tin[u]) ^ pointQuery(tin[v]) ^ (1 << (s[w] - 'a'));
                res.add((mask & (mask - 1)) == 0);
            }
            else {
                int u = Integer.parseInt(q[1]);
                char c = q[2].charAt(0);

                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                s[u] = c;
                rangeUpdate(tin[u], tout[u], delta);
            }
        }

        return res;
    }

    private void init(int n, int[][] es, String str){
        this.n = n;
        edges = new ArrayList<>();

        for (int i=0; i<n; ++i){
            edges.add(new ArrayList<>());
        }

        for (int[] edge : es){
            int u = edge[0];
            int v = edge[1];

            edges.get(u).add(v);
            edges.get(v).add(u);
        }

        this.s = str.toCharArray();

        build();
    }

    private void build(){
        tin = new int[n];
        tout = new int[n];
        depth = new int[n];
        up = new int[LOG][n];

        int[] prefix = new int[n];
        int[] order = new int[n];
        int[] size = new int[n];
        int idx = 0;

        ArrayDeque<Integer> stack = new ArrayDeque<>();
        up[0][0] = 0;
        stack.push(0);

        while (!stack.isEmpty()){
            int u = stack.pop();
            tin[u] = idx;
            order[idx++] = u;

            int p = up[0][u];
            prefix[u] = (u == 0 ? 0 : prefix[p]) ^ (1 << (s[u] - 'a'));

            for (int v : edges.get(u)){
                if (v == p) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                stack.push(v);
            }
        }

        for (int i = n - 1; i >= 0; --i){
            int u = order[i];
            size[u] += 1;
            tout[u] = tin[u] + size[u] - 1;

            if (u != 0) size[up[0][u]] += size[u];
        }

        for (int k = 1; k < LOG; ++k){
            for (int v = 0; v < n; ++v){
                up[k][v] = up[k - 1][up[k - 1][v]];
            }
        }

        tag = new int[2 * n];
        for (int u = 0; u < n; ++u){
            tag[n + tin[u]] = prefix[u];
        }
    }

    private void rangeUpdate(int l, int r, int val){
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
            if ((l & 1) == 1) tag[l++] ^= val;
            if ((r & 1) == 1) tag[--r] ^= val;
        }
    }

    private int pointQuery(int p){
        int res = 0;
        for (int i = p + n; i >= 1; i >>= 1){
            res ^= tag[i];
        }
        return res;
    }

    private int lca(int u, int v){
        if (depth[u] < depth[v]){
            int t = u; u = v; v = t;
        }

        int diff = depth[u] - depth[v];
        for (int k = 0; k < LOG; ++k){
            if (((diff >> k) & 1) == 1) u = up[k][u];
        }
        if (u == v)
            return u;

        for (int k = LOG - 1; k >= 0; --k){
            if (up[k][u] != up[k][v]){
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
    }
}