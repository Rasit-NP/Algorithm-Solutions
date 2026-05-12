# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int ans = 0, now = 0;
        for (const auto& task : tasks){
            if (now < task[1]){
                ans += (task[1] - now);
                now = task[1];
            }
            now -= task[0];
        }

        return ans;
    }
};