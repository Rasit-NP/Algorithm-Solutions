import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

class Solution {

    int n, m;
    String s;
    List<Integer> indexOfParentheses = new ArrayList<>();

    public List<String> removeInvalidParentheses(String s) {
        this.s = s;
        this.n = s.length();
        int minOfRemovals = 30;
        
        Set<String> res = new HashSet<>();
        List<Integer> resultOfBit = new ArrayList<>();

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);
            if (c == '(' || c == ')'){
                indexOfParentheses.add(i);
            }
        }

        this.m = indexOfParentheses.size();
        
        for (int i=0; i<(1<<m); ++i){
            int numOfRemovals = 0;
            for (int j=0; j<m; ++j){
                if ((i & (1 << j)) == 0){
                    ++numOfRemovals;
                }
            }
            if (numOfRemovals > minOfRemovals)
                continue;

            if (validate(i)){
                if (numOfRemovals < minOfRemovals){
                    resultOfBit = new ArrayList<>();
                    resultOfBit.add(i);
                    minOfRemovals = numOfRemovals;
                }
                else if (numOfRemovals == minOfRemovals){
                    resultOfBit.add(i);
                }
            }
        }

        for (int bit : resultOfBit){
            res.add(createString(bit));
        }

        return res.stream().toList();
    }

    private String createString(int bit){
        int bitIndex = 1;
        int[] isIncluded = new int[n];

        Arrays.fill(isIncluded, 1);

        for (int i=0; i<m; ++i){
            if ((bit & (1 << i)) == 0){
                isIncluded[indexOfParentheses.get(i)] = 0;
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int i=0; i<n; ++i){
            if (isIncluded[i] == 1){
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }

    private boolean validate(int bit){
        int now = 0;
        for (int i=0; i<m; ++i){
            int b = bit & (1 << i);
            if (b == 0)
                continue;
            
            char c = s.charAt(indexOfParentheses.get(i));

            if (c == '('){
                ++now;
            }
            else {
                --now;
            }

            if (now < 0)
                return false;
        }
        return now == 0;
    }
}