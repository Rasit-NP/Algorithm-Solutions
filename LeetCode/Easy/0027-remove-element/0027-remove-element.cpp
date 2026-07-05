# include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> vec;
        for (int num : nums){
            if (num != val){
                vec.push_back(num);
            }
        }

        nums = vec;
        return nums.size();
    }
};