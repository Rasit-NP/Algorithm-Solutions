# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0;
        int first = 0, second = 0;

        for (int num : nums){
            if (num > first){
                second = first;
                first = num;
            }
            else if (num > second){
                second = num;
            }
        }

        res = (first-1) * (second-1);

        return res;
    }
};