# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = 5000;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int local = min(max(landStartTime[i]+landDuration[i], waterStartTime[j]) + waterDuration[j],\
                                max(waterStartTime[j]+waterDuration[j], landStartTime[i]) + landDuration[i]);
                ans = min(ans, local);
            }
        }

        return ans;
    }
};