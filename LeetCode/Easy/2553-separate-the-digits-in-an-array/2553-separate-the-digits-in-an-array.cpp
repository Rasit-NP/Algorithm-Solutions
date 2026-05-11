# include <vector>
# include <stack>
using namespace std;

class Solution {
private:
    vector<int> ans;
public:
    vector<int> separateDigits(vector<int>& nums) {
        for (int num : nums){
            stack<int> stk;
            while (num){
                stk.push(num%10);
                num /= 10;
            }
            while (stk.size()){
                ans.push_back(stk.top());   stk.pop();
            }
        }

        return ans;
    }
};