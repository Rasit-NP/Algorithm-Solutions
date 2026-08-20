# include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2, res;
        arr1.emplace_back(nums[0]);
        arr2.emplace_back(nums[1]);
        res.reserve(n);

        for (int i=2; i<n; i++){
            if (arr1.back() > arr2.back()){
                arr1.emplace_back(nums[i]);
            }
            else {
                arr2.emplace_back(nums[i]);
            }
        }

        for (int num : arr1){
            res.emplace_back(num);
        }
        for (int num : arr2){
            res.emplace_back(num);
        }

        return res;
    }
};