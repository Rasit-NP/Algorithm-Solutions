import java.util.HashMap;
import java.util.PriorityQueue;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> cnt.get(b) - cnt.get(a));

        for (int num : nums){
            cnt.put(num, cnt.getOrDefault(num, 0) + 1);
        }

        for (int key : cnt.keySet()){
            System.out.println(key + " " + cnt.get(key));
            pq.add(key);
        }

        int[] res = new int[k];
        for (int i=0; i<k; i++){
            res[i] = pq.peek();
            pq.poll();
        }

        return res;
    }
}