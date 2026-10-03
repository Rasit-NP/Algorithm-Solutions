import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

class Solution {
    private record Cluster(int s, int e){
    }

    public int longestValidParentheses(String s) {
        int res = 0;
        int n = s.length();
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        List<Cluster> clusters = new ArrayList<>();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);
            if (dq.size() == 0 || c == '('){
                dq.addLast(i);
            }
            else if (c == ')'){
                int j = dq.peekLast();
                if (s.charAt(j) == '('){
                    Cluster now = new Cluster(j, i);
                    if (clusters.size() == 0){
                        clusters.add(now);
                    }
                    else {

                        while (clusters.size() > 0){
                            Cluster last = clusters.get(clusters.size() - 1);
                            if (now.s == last.e+1){
                                clusters.remove(clusters.size() - 1);
                                now = new Cluster(last.s, now.e);
                            }
                            else if (now.s < last.s && now.e > last.e){
                                clusters.remove(clusters.size() - 1);
                            }
                            else {
                                break;
                            }
                        }
                        clusters.add(now);
                    }
                    dq.removeLast();
                }
                else {
                    dq.addLast(i);
                }
            }
        }

        for (int i=0; i<clusters.size(); ++i){
            Cluster cluster = clusters.get(i);
            res = Math.max(res, cluster.e - cluster.s + 1);
        }

        return res;
    }
}