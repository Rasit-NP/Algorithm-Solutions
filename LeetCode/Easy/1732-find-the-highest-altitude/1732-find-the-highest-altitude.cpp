# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int now = 0, res = 0;
        int n = gain.size();

        for (int i=0; i<n; i++){
            now = gain[i] + now;
            res = max(res, now);
        }

        return res;
    }
};