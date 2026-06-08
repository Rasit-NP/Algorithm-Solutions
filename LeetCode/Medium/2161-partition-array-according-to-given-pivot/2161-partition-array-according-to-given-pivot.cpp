class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res;
        res.reserve(n);

        for (int num : nums){
            if (num < pivot){
                res.emplace_back(num);
            }
        }

        for (int num : nums){
            if (num == pivot){
                res.emplace_back(num);
            }
        }

        for (int num : nums){
            if (num > pivot){
                res.emplace_back(num);
            }
        }

        return res;
    }
};