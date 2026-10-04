# include <numeric>
using namespace std;

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* now = head;
        while (now -> next != nullptr){
            ListNode* next = now->next;
 
            int val = gcd(now->val, next->val);

            now->next = new ListNode(val, next);
            now = next;
        }

        return head;
    }
};