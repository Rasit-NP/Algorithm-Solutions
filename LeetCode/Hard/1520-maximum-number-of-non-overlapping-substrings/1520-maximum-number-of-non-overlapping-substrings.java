import java.util.*;

class Solution {

    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();
        int[][] ranges = new int[26][2];

        for (int[] range : ranges){
            Arrays.fill(range, -1);
        }

        for (int i=0; i<n; ++i){
            char c = s.charAt(i);
            int idx = c - 'a';
            if (ranges[idx][0] == -1){
                ranges[idx][0] = i;
            }
            ranges[idx][1] = i;
        }

        for (char c='a'; c<='z'; ++c){
            int i = c - 'a';
            if (ranges[i][0] == -1)
                continue;
            Set<Character> set = new HashSet<>();
            for (int j=ranges[i][0]; j<=ranges[i][1]; ++j){
                set.add(s.charAt(j));
            }

            int l = ranges[i][0];
            int r = ranges[i][1];
            int leftLim = l;
            int rightLim = r;
            for (int c2 : set){
                leftLim = Math.min(leftLim, ranges[c2-'a'][0]);
                rightLim = Math.max(rightLim, ranges[c2-'a'][1]);
            }
            while (l != leftLim || r != rightLim){
                for (int j=l-1; j>=leftLim; --j){
                    set.add(s.charAt(j));
                }
                for (int j=r+1; j<=rightLim; ++j){
                    set.add(s.charAt(j));
                }

                l = leftLim;
                r = rightLim;

                for (char c2 : set){
                    leftLim = Math.min(leftLim, ranges[c2-'a'][0]);
                    rightLim = Math.max(rightLim, ranges[c2-'a'][1]);
                }
            }
            ranges[i][0] = leftLim;
            ranges[i][1] = rightLim;
        }

        Arrays.sort(ranges, (a, b) -> Integer.compare(a[1], b[1]));

        int last = -1;
        List<String> res = new ArrayList<>();

        for (int[] range : ranges){
            if (range[0] > last){
                res.add(s.substring(range[0], range[1] + 1));
                last = range[1];
            }
        }

        return res;
    }
}