# include <vector>
# include <algorithm>
using namespace std;


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int res = n;
        int maxR = 0;

        for (vector<int>& interval : intervals){
            if (interval[1] <= maxR){
                --res;
            }
            else {
                maxR = interval[1];
            }
        }

        return res;
    }
};