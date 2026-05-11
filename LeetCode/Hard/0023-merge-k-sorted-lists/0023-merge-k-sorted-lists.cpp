# include <vector>
# include <climits>
using namespace std;

class Solution {
private:
    int k;
    ListNode* ans;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        k = lists.size();
        if (k == 0){
            return ans;
        }
        int mini = INT_MAX;
        int idx;
        for (int i=0; i<k; i++){
            ListNode* li = lists[i];
            if (li == NULL){
                continue;
            }
            if (li->val < mini){
                mini = li->val;
                idx = i;
            }
        }
        if (mini == INT_MAX){
            return ans;
        }
        ans = new ListNode(mini, nullptr);
        lists[idx] = lists[idx] -> next;
        ListNode* now = ans;

        while (true){
            int cntNull = 0;
            mini = INT_MAX;
            for (int i=0; i<k; i++){
                ListNode* li = lists[i];
                if (li == NULL){
                    ++cntNull;
                    continue;
                }
                if (li->val < mini){
                    mini = li->val;
                    idx = i;
                }
            }
            if (cntNull == k){
                break;
            }
            now -> next = new ListNode(mini, nullptr);
            now = now -> next;
            lists[idx] = lists[idx] -> next;
        }

        return ans;
    }
};