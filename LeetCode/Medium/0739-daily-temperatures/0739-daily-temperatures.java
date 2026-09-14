import java.util.ArrayDeque;

class Data{
    int idx;
    int temperature;

    Data(int idx, int temperature){
        this.idx = idx;
        this.temperature = temperature;
    }
}

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        ArrayDeque<Data> stk = new ArrayDeque<>();
        int[] res = new int[n];

        for (int i=0; i<n; ++i){
            int tmp = temperatures[i];
            
            while (!stk.isEmpty() && tmp > stk.peekLast().temperature){
                int idx = stk.peekLast().idx;   stk.removeLast();
                res[idx] = i - idx;
            }

            stk.addLast(new Data(i, tmp));
        }

        return res;
    }
}