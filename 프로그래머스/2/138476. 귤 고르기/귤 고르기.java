import java.util.Arrays;

class Solution {
    public int solution(int k, int[] tangerine) {
        int[] cnt = new int[10_000_001];
        for (int num : tangerine)
            ++cnt[num];
        Arrays.sort(cnt);
        
        int res = 0;
        int now = 0;
        
        for (int i=10_000_000; i>=0; --i){
            if (now < k){
                ++res;
                now += cnt[i];
            }
            else {
                break;
            }
        }
            
        return res;
    }
}