# include <vector>
# include <algorithm>
# include <numeric>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = 1000, large = 1;
        for (int num : nums){
            small = min(small, num);
            large = max(large, num);
        }

        return gcd(small, large);
    }
};