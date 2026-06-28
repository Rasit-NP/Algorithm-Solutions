# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int res = 0;
        int now = 1;
        for (int num : arr){
            if (num >= now){
                res = max(res, now);
                ++now;
            }
        }

        return res;
    }
};