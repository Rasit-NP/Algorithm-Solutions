class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode now = head;

        if (now == null)
            return head;

        while (now.next != null){
            if (now.val == now.next.val){
                now.next = now.next.next;
            }
            else {
                now = now.next;
            }
        }

        return head;
    }
}