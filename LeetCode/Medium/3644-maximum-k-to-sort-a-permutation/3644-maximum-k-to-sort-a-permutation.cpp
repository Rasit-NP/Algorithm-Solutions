# include <vector>
# include <climits>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int res = INT_MAX;

        for (int i=0; i<n; ++i){
            int num = nums[i];

            if (num != i){
                res &= num;
            }
        }

        return (res == INT_MAX ? 0 : res);
    }
};