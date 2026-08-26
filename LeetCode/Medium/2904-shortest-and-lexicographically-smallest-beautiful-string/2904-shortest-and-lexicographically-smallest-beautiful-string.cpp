# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int n = s.size();
        int head = 0, tail = 0;
        int cnt = 0;
        while (tail < n){
            if (s[tail++] == '1'){
                ++cnt;
            }
            while (cnt > k){
                if (s[head++] == '1')
                    --cnt;
            }
            while(s[head] == '0'){
                ++head;
            }
            if (cnt == k){
                string now = s.substr(head, tail-head);
                if (res == ""){
                    res = now;
                    continue;
                }
                else if (res.size() > tail-head){
                    res = now;
                }
                else if (res.size() == tail-head){
                    res = min(res, now);
                }
            }
        }

        return res;
    }
};