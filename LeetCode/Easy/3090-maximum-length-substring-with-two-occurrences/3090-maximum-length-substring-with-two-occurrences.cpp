# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = s.size();
        int cnt[26] {0};
        int front = 0, end = 0;

        int res = 0;
        while (end < len){
            int idx = s[end++] - 'a';
            ++cnt[idx];
            while (cnt[idx] > 2){
                int id = s[front++] - 'a';
                --cnt[id];
            }

            res = max(res, end-front);
        }

        return res;
    }
};