# include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3){
            return n;
        }
        int cnt = 0;
        while (n){
            n >>= 1;
            ++cnt;
        }

        return 1 << cnt;
    }
};