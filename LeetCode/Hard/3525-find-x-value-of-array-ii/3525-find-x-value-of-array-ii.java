class Solution {

    private static int N;
    private static int K;

    class SegTree{

        record Data(int rangeMod, long[] left, long[] middle, long[] right, long[] total) {
            public Data(){
                this(1, new long[Solution.K], new long[Solution.K], new long[Solution.K], new long[Solution.K]);
            }

            public static Data plus(Data a, Data b){
                if (a.isEmpty())
                    return b;
                if (b.isEmpty())
                    return a;
                int k = Solution.K;
                
                int newRangeMod = (a.rangeMod * b.rangeMod) % k;
                long[] newLeft = new long[k];
                long[] newMiddle = new long[k];
                long[] newRight = new long[k];
                long[] newTotal = new long[k];

                newTotal[newRangeMod] = 1;

                for (int i=0; i<k; ++i){
                    newLeft[i] += a.left[i] + a.total[i];
                    newRight[i] += b.right[i] + b.total[i];
                }
                for (int i=0; i<k; ++i){
                    for (int j=0; j<k; ++j){
                        int id = (i*j) % k;

                        newMiddle[id] += a.right[i] * b.left[j];
                        newLeft[id] += a.total[i] * b.left[j];
                        newRight[id] += a.right[i] * b.total[j];
                    }
                }

                return new Data(newRangeMod, newLeft, newMiddle, newRight, newTotal);
            }

            public boolean isEmpty(){
                for (long v : total){
                    if (v > 0)
                        return false;
                }
                return true;
            }
        }

        public int sz = 1;
        private Data[] tree;

        public SegTree(int[] nums, int k){
            int n = N;

            while (sz < n){
                sz <<= 1;
            }

            tree = new Data[2*sz];

            for (int i=0; i<n; ++i){
                int mod = nums[i] % k;

                long[] left = new long[k];
                long[] middle = new long[k];
                long[] right = new long[k];
                long[] total = new long[k];

                total[mod] = 1;

                tree[i+sz] = new Data(mod, left, middle, right, total);
            }

            for (int i=n; i<sz; ++i){
                tree[i+sz] = new Data();
            }

            for (int i=sz-1; i>0; --i){
                tree[i] = Data.plus(tree[2*i], tree[2*i+1]);
            }
        }

        public void update(int id, int v){
            int k = Solution.K;
            int idx = sz + id;
            int num = v % K;

            long[] left = new long[k];
            long[] middle = new long[k];
            long[] right = new long[k];
            long[] total = new long[k];

            total[v % K] = 1;

            tree[idx] = new Data(num, left, middle, right, total);

            idx >>= 1;

            for (; idx>0; idx >>= 1){
                tree[idx] = Data.plus(tree[2*idx], tree[2*idx+1]);
            }
        }

        public int query(int start, int x){
            Data left = new Data(1, new long[K], new long[K], new long[K], new long[K]);
            Data right = new Data(1, new long[K], new long[K], new long[K], new long[K]);

            int l = start + sz;
            int r = N + sz - 1;

            while (l <= r){
                if ((l&1) == 1){
                    left = Data.plus(left, tree[l++]);
                }
                if ((r&1) == 0){
                    right = Data.plus(tree[r--], right);
                }
                l >>= 1;
                r >>= 1;
            }

            Data res = Data.plus(left, right);

            return (int)(res.left[x] + res.total[x]);
        }
    }


    public int[] resultArray(int[] nums, int k, int[][] queries) {
        this.N = nums.length;
        this.K = k;

        SegTree segTree = new SegTree(nums, k);
        int Q = queries.length;

        int[] res = new int[Q];

        for (int q=0; q<Q; ++q){
            int[] query = queries[q];

            segTree.update(query[0], query[1]);
            res[q] = segTree.query(query[2], query[3]);
        }

        return res;
    }
}