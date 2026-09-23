class Solution {

    private int n;
    private int[] visited;
    private List<Integer> res;

    private void travle(int nowBit){
        System.out.println(nowBit);
        if (res.size() == (1<<n))
            return;

        for (int i=0; i<n; ++i){
            int bit = nowBit ^ (1 << i);
            if (visited[bit] == 0){
                visited[bit] = 1;
                res.add(bit);
                travle(bit);
                if (res.size() == (1<<n))
                    return;
                res.remove(res.size() - 1);
                visited[bit] = 0;
            }
        }
    }

    public List<Integer> grayCode(int n) {
        this.n = n;

        res = new ArrayList<>();

        visited = new int[1<<n];

        visited[0] = 1;
        res.add(0);

        travle(0);

        return res;
    }
}