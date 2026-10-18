class SegTree{
    int n;
    int sz = 1;
    long[] tree;
    long[] lazy;

    public static final int MOD = 1_000_000_007;

    public SegTree(int n){
        this.n = n;
        while (sz < n){
            sz <<= 1;
        }

        tree = new long[2*sz];
        lazy = new long[2*sz];
    }

    public void plusTree(int i, long v){
        tree[i] += v;
        if (tree[i] >= MOD)
            tree[i] -= MOD;
    }

    public void plusLazy(int i, long v){
        lazy[i] += v;
        if (lazy[i] >= MOD)
            lazy[i] -= MOD;
    }

    public void plusOneForRange(int a, int b){
        if (a == b)
            return;
        plusOneForRange(1, 0, sz, a, b);
    }

    public void plusOneForRange(int i, int l, int r, int a, int b){
        int mid = (l + r) / 2;

        if (a == l && b == r){
            plusTree(i, b-a);
            if (i < sz){
                plusLazy(2*i, (b-a)/2);
                plusLazy(2*i+1, (b-a)/2);
            }
        }
        else if (b <= mid){
            plusTree(i, b-a);
            plusOneForRange(2*i, l, mid, a, b);
        }
        else if (a >= mid){
            plusTree(i, b-a);
            plusOneForRange(2*i+1, mid, r, a, b);
        }
        else {
            plusTree(i, b-a);
            plusOneForRange(2*i, l, mid, a, mid);
            plusOneForRange(2*i+1, mid, r, mid, b);
        }
    }

    public long getRange(int a, int b){
        if (a == b)
            return 0;
        return getRange(1, 0, sz, a, b);
    }

    public long getRange(int i, int l, int r, int a, int b){
        int mid = (l + r) / 2;

        if (lazy[i] != 0){
            plusTree(i, lazy[i]);
            if (i < sz){
                plusLazy(2*i, lazy[i]/2);
                plusLazy(2*i+1, lazy[i]/2);
            }
            lazy[i] = 0;
        }

        long res = 0;
        if (a == l && b == r){
            res = tree[i];
        }
        else if (b <= mid){
            res = getRange(2*i, l, mid, a, b);
        }
        else if (a >= mid){
            res = getRange(2*i+1, mid, r, a, b);
        }
        else {
            res = getRange(2*i, l, mid, a, mid) + getRange(2*i+1, mid, r, mid, b);
            if (res >= MOD)
                res -= MOD;
        }

        return res;
    }
}

class Solution {

    private final int maxNum = 100_000;

    public int sumCounts(int[] nums) {
        int n = nums.length;
        int[] lastIdx = new int[maxNum+1];

        SegTree tree = new SegTree(n);

        Arrays.fill(lastIdx, -1);

        long res = 1;
        long cur = 1;
        lastIdx[nums[0]] = 0;

        tree.plusOneForRange(0, 1);

        for (int i=1; i<n; ++i){
            int num = nums[i];
            
            int last = lastIdx[num];

            cur += 2 * tree.getRange(last+1, i) + i - last;
            while (cur >= SegTree.MOD)
                cur -= SegTree.MOD;

            tree.plusOneForRange(last+1, i+1);

            res += cur;
            if (res >= SegTree.MOD)
                res -= SegTree.MOD;

            lastIdx[num] = i;
        }

        return (int)res;
    }
}