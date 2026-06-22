# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {0};
        for (char let : text){
            cnt[let-'a'] += 1;
        }
        int res = 1'000'000;
        res = min(res, cnt['b'-'a']);
        res = min(res, cnt['a'-'a']);
        res = min(res, cnt['l'-'a']/2);
        res = min(res, cnt['o'-'a']/2);
        res = min(res, cnt['n'-'a']);

        return res;
    }
};