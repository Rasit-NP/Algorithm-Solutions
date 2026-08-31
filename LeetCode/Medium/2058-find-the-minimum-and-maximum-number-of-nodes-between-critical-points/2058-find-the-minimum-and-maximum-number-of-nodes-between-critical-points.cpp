# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = 1'000'000;
        int maxDist = -1;
        int idx = 0;
        int before = -1;
        int first;
        while (head->next != nullptr && head->next->next != nullptr){
            int pre = head->val;
            int now = head->next->val;
            int next = head->next->next->val;
            if (now > max(pre, next) || now < min(pre, next)){
                if (before != -1){
                    minDist = min(minDist, idx-before);
                    maxDist = idx-first;
                }
                else {
                    first = idx;
                }
                before = idx;
            }
            head = head->next;
            ++idx;
        }

        if (minDist == 1'000'000)
            minDist = -1;
        return {minDist, maxDist};
    }
};