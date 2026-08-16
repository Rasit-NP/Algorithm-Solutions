# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int stone : stones){
            ++cnt[stone%3];
        }

        if (cnt[0] & 1){
            return abs(cnt[1] - cnt[2]) > 2;
        }
        else {
            return cnt[1] && cnt[2];
        }
    }
};