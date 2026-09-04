import java.util.ArrayDeque;

class Solution {
    private List<String> parse(String log){
        List<String> res = new ArrayList<>();

        int c1 = log.indexOf(":");
        int c2 = log.lastIndexOf(":");

        res.add(log.substring(0, c1));
        res.add(log.substring(c1+1, c2));
        res.add(log.substring(c2+1));

        return res;
    }

    public int[] exclusiveTime(int n, List<String> logs) {
        int[] res = new int[n];
        ArrayDeque<Integer> stk = new ArrayDeque<>();

        int latestTime = 0;
        
        for (String log : logs){
            List<String> parsedLog = parse(log);
            int idx = Integer.parseInt(parsedLog.get(0));
            String oper = parsedLog.get(1);
            int t = Integer.parseInt(parsedLog.get(2));

            if (stk.isEmpty()){
                stk.push(idx);
                latestTime = t;
            }
            else if (oper.equals("start")){
                res[stk.peek()] += t - latestTime;
                stk.push(idx);
                latestTime = t;
            }
            else {
                res[stk.peek()] += t - latestTime + 1;
                stk.pop();
                latestTime = t + 1;
            }
        }

        return res;
    }
}