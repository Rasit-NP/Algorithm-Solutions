# include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        
        vector<int> nums;
        while (x){
            nums.push_back(x%10);
            x /= 10;
        }

        int sz = nums.size();
        bool check = true;
        for (int i=0; i<sz; i++){
            if (nums[i] != nums[sz-i-1]){
                check = false;
                break;
            }
        }
        return check;
    }
};