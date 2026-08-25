# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int find = k;
        for (int num : nums){
            if (num >= find + k)
                return find;
            else if (num == find)
                find += k;
        }
        return find;
    }
};