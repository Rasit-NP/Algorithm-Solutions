# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n;
public:
    int findMin(vector<int>& nums) {
        int ans = 5000;
        for(int num : nums){
            ans = min(ans, num);
        }

        return ans;
    }
};