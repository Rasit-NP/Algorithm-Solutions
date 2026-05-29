# include <algorithm>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = 100000;

        for (int num : nums){
            int local = 0;
            while (num){
                local += num%10;
                num /= 10;
            }
            res = min(res, local);
        }

        return res;
    }
};