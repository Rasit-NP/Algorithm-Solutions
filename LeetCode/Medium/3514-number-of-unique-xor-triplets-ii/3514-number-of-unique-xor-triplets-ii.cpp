# include <unordered_set>
# include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> mid, fin;

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mid.insert(nums[i] ^ nums[j]);
            }
        }

        for (int i=0; i<n; i++){
            for (int num : mid){
                fin.insert(num ^ nums[i]);
            }
        }

        return fin.size();
    }
};