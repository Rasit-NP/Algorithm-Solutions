class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0){
            return head;
        }
        ListNode* now = head;
        ListNode* tail;
        int cnt = 1;
        while (now->next != nullptr){
            now = now->next;
            ++cnt;
        }
        tail = now;
        now = head;

        k %= cnt;
        if (!k){
            return head;
        }
        k = cnt-k;

        for (int i=0; i<k-1; i++){
            now = now->next;
        }

        ListNode* ans = now->next;
        now->next = nullptr;
        tail->next = head;
        return ans;
    }
};