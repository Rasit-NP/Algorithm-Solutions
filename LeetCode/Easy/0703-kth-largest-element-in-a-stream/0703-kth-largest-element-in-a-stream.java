import java.util.PriorityQueue;

class KthLargest {

    int k;
    private PriorityQueue<Integer> pq;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.pq = new PriorityQueue<>();

        for (int num : nums){
            pq.add(num);
        }

        while (pq.size() > k){
            pq.poll();
        }
    }
    
    public int add(int val) {
        pq.add(val);
        while (pq.size() > k)
            pq.poll();

        return pq.peek();
    }
}