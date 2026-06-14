# include <vector>
# include <algorithm>
using namespace std;

class Solution {
private:
    int n, res=0;
    vector<int> nums;
public:
    int pairSum(ListNode* head) {
        nums.reserve(100'000);
        while (head != nullptr){
            nums.push_back(head->val);
            head = head->next;
        }
        n = nums.size();

        for (int i=0; i<(n/2); i++){
            res = max(res, nums[i]+nums[n-i-1]);
        }

        return res;
    }
};