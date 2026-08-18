# include <vector>
# include <set>
# include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int res = -1;
        vector<int> cnt(51, 0);
        for (int i=0, j=k-1; j<n; i++, j++){
            set<int> mySet;
            for (int x=i; x<=j; x++){
                mySet.insert(nums[x]);
            }
            for (int num : mySet){
                ++cnt[num];
            }
        }

        for (int i=0; i<=50; i++){
            if (cnt[i] == 1){
                res = max(res, i);
            }
        }

        return res;
    }
};