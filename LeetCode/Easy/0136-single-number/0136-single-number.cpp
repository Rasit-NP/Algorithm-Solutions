# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> appeared;
        for (int num : nums){
            if (appeared.find(num) == appeared.end()){
                appeared.insert(num);
            }
            else {
                appeared.erase(num);
            }
        }

        for (int num : appeared)
            return num;
        return 0;
    }
};