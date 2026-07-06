# include <vector>
# include <algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    if (a[0] < b[0]){
        return true;
    }
    else if (a[0] == b[0] && a[1] > b[1]){
        return true;
    }
    else {
        return false;
    }
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = n;
        vector<int> isDeleted(n, 0);
        sort(intervals.begin(), intervals.end(), compare);

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1] && !isDeleted[j]){
                    --res;
                    isDeleted[j] = 1;
                }
            }
        }

        return res;
    }
};