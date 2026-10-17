# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int getValue(int x){
        int res = 0;
        while (x){
            res += x % 10;
            x /= 10;
        }
        return res;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vs(n, vector<int>(3));

        for (int i=0; i<n; ++i){
            vs[i] = {getValue(nums[i]), nums[i], i};
        }

        sort(vs.begin(), vs.end());

        int res = 0;

        for (int i=0; i<n; ++i){
            vector<int>& v = vs[i];

            int idx = v[2];

            while (idx != i){
                swap(vs[i][2], vs[idx][2]);
                idx = v[2];
                ++res;
            }
        }
        return res;
    }
};
