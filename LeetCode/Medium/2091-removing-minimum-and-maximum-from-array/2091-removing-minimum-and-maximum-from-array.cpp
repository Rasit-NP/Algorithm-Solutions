# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minV = 100'001, maxV = -100'001;
        int minI, maxI;
        for (int i=0; i<n; i++){
            int num = nums[i];
            if (num < minV){
                minV = num;
                minI = i;
            }
            if (num > maxV){
                maxV = num;
                maxI = i;
            }
        }

        int l = min(minI, maxI);
        int r = max(minI, maxI);

        return min({l+1 + n-r, r+1, n-l});
    }
};