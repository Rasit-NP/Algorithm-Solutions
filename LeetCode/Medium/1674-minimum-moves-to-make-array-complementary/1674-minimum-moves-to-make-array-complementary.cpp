# include <vector>
# include <cmath>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    int limit;
    vector<int> diff;
public:
    int minMoves(vector<int>& nums, int limit) {
        n = nums.size();
        int diffSize = 2*limit+2;
        this->limit = limit;

        diff.assign(diffSize, 0);
        for (int i=0; i<n/2; i++){
            int a = nums[i], b = nums[n-i-1];
            int mini = min(a, b), maxi = max(a, b);

            if (mini > 1){
                diff[2] += 2;
                diff[mini+1] -= 2;
            }
            diff[mini+1] += 1;
            diff[mini+maxi] -= 1;

            diff[mini+maxi+1] += 1;
            diff[maxi+limit+1] -= 1;

            if (maxi < limit){
                diff[maxi+limit+1] += 2;
                diff[2*limit+1] -= 2;
            }
        }

        int ans = INT_MAX;
        for (int i=0; i<diffSize-1; i++){
            diff[i+1] += diff[i];
            if (i>1 && i<=2*limit){
                ans = min(ans, diff[i]);
            }
        }
        return ans;
    }
};