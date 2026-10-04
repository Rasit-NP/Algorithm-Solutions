/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

# include <numeric>
using namespace std;

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* now = head;
        while (now -> next != nullptr){
            ListNode* next = now->next;
            int a = now->val;
            int b = next->val;
            int val = gcd(a, b);

            now->next = new ListNode(val, next);
            now = next;
        }

        return head;
    }
};