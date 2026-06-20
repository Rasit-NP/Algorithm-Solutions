using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* now = res;
        while (true){
            if (list1 == nullptr && list2 == nullptr){
                break;
            }

            if (list1 == nullptr){
                now->next = new ListNode(list2->val);
                now = now->next;
                list2 = list2->next;
            }
            else if (list2 == nullptr){
                now->next = new ListNode(list1->val);
                now = now->next;
                list1 = list1->next;
            }
            else if (list1->val < list2->val){
                now->next = new ListNode(list1->val);
                now = now->next;
                list1 = list1->next;
            }
            else{
                now->next = new ListNode(list2->val);
                now = now->next;
                list2 = list2->next;
            }
        }

        return res->next;
    }
};