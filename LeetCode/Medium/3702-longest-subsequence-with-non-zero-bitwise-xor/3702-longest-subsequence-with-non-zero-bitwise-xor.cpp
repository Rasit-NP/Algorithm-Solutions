# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int val = 0;
        bool chk = false;
        for (int i=0; i<n; i++){
            int num = nums[i];
            val ^= num;
            if (num)
                chk = true;
        }

        if (val)
            return n;
        else {
            return (chk ? n-1 : 0);
        }
    }
};