import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;

class Solution {
    public int shortestPath(int n, int[][] es, String labels, int k) {
        System.out.println(es.length);
        
        List<List<Edge>> edges = new ArrayList<>();
        
        PriorityQueue<Data> pq = new PriorityQueue<>(
            (a, b) -> a.val() - b.val()
        );
        
        int[][] visited = new int[n][k];
        
        for (int i=0; i<n; ++i){
            edges.add(new ArrayList<>());
            
            Arrays.fill(visited[i], 1<<30);
        }
        
        for (int[] edge : es){
            int u = edge[0], v = edge[1], w = edge[2];
            edges.get(u).add(new Edge(v, w));
        }

        pq.add(new Data(0, 0, 0));
        visited[0][0] = 0;

        while (pq.size() > 0){
            Data now = pq.peek();   pq.remove();

            int x = now.x();
            int consec = now.consec();
            int val = now.val();

            if (x == n-1)
                break;
            
            if (visited[x][consec] < val)
                continue;

            for (Edge edge : edges.get(x)){
                int nx = edge.nx();
                int weight = edge.weight();

                int newConsec = (labels.charAt(x) == labels.charAt(nx) ? consec + 1 : 0);
                if (newConsec >= k)
                    continue;
                
                if (visited[nx][newConsec] <= val + weight)
                    continue;
                
                visited[nx][newConsec] = val + weight;
                pq.add(new Data(nx, newConsec, val + weight));
            }
        }

        int res = 1 << 30;

        for (int consec=0; consec<k; ++consec){
            res = Math.min(res, visited[n-1][consec]);
        }

        return res != (1<<30) ? res : -1;
    }

    private record Data(int x, int consec, int val){}
    private record Edge(int nx, int weight){}
}