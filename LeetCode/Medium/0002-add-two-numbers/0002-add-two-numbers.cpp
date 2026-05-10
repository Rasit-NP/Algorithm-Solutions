# include <vector>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        vector<int> va;
        int nextUp = 0;
        int val = l1->val + l2->val + nextUp;
        nextUp = val/10;
        va.push_back(val%10);
        while (l1->next != nullptr || l2->next != nullptr){
            if (l1->next == nullptr){
                l1->next = new ListNode();
            }
            if (l2->next == nullptr){
                l2->next = new ListNode();
            }
            l1 = l1->next;
            l2 = l2->next;
            val = l1->val + l2->val + nextUp;
            nextUp = val/10;
            va.push_back(val%10);
        }

        if (nextUp){
            va.push_back(nextUp);
        }

        int n = va.size();

        ans = new ListNode(va[n-1]);
        for (int i=n-2; i>=0; i--){
            ans = new ListNode(va[i], ans);
        }

        return ans;
    }
};