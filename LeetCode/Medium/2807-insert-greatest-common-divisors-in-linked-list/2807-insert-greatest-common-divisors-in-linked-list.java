class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode now = head;

        while (now.next != null){
            int val = getGcd(now.val, now.next.val);

            ListNode gcdNode = new ListNode(val, now.next);

            now.next = gcdNode;
            now = now.next.next;
        }

        return head;
    }

    private int getGcd(int a, int b){
        if (a < b){
            int tmp = a;
            a = b;
            b = tmp;
        }

        while (a % b != 0){
            int tmp = a % b;
            a = b;
            b = tmp;
        }

        return b;
    }
}