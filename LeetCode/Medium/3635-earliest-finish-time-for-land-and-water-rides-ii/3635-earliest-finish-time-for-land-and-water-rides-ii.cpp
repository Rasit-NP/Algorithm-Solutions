# include <vector>
# include <algorithm>
# include <climits>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int res = INT_MAX;

        int landFirst = INT_MAX;
        int waterSecond = INT_MAX;
        for (int i=0; i<n; i++){
            landFirst = min(landFirst, landStartTime[i] + landDuration[i]);
        }
        for (int i=0; i<m; i++){
            waterSecond = min(waterSecond, max(landFirst, waterStartTime[i])+waterDuration[i]);
        }

        int waterFirst = INT_MAX;
        int landSecond = INT_MAX;
        for (int i=0; i<m; i++){
            waterFirst = min(waterFirst, waterStartTime[i] + waterDuration[i]);
        }
        for (int i=0; i<n; i++){
            landSecond = min(landSecond, max(waterFirst, landStartTime[i]) + landDuration[i]);
        }

        return min(waterSecond, landSecond);
    }
};