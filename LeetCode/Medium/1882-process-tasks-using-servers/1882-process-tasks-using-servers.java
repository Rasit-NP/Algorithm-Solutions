import java.util.PriorityQueue;

class Solution {

    public int[] assignTasks(int[] servers, int[] tasks) {

        int s = servers.length;
        int n = tasks.length;
        int[] res = new int[n];

        PriorityQueue<Server> onServers = new PriorityQueue<>(
            (a, b) -> a.w() != b.w() ? Integer.compare(a.w(), b.w()) : Integer.compare(a.idx(), b.idx())
        );
        PriorityQueue<Task> nowWorking = new PriorityQueue<>((a, b) -> Integer.compare(a.endAt(), b.endAt()));

        for (int i=0; i<s; ++i){
            onServers.add(new Server(servers[i], i));
        }

        for (int i=0, time=0; i<n;){
            while (nowWorking.size() > 0 && nowWorking.peek().endAt() <= time){
                Task endTask = nowWorking.poll();
                int serverIdx = endTask.serverIdx();
                onServers.add(new Server(servers[serverIdx], serverIdx));
            }
            
            if (onServers.isEmpty()){
                time = nowWorking.peek().endAt();
                continue;
            }

            int task = tasks[i];
            Server server = onServers.poll();

            res[i] = server.idx();
            nowWorking.add(new Task(time+task, server.idx()));
            ++i;
            time = Math.max(time, i);
        }

        return res;
    }

    private record Server(int w, int idx){}

    private record Task(int endAt, int serverIdx){}
}