import java.util.ArrayDeque;

class MyQueue {

    Deque<Integer> stk1, stk2;

    public MyQueue() {
        stk1 = new ArrayDeque<>();
        stk2 = new ArrayDeque<>();
    }
    
    public void push(int x) {
        stk1.addLast(x);
    }
    
    public int pop() {
        change(stk1, stk2);
        int res = stk2.peekLast();  stk2.removeLast();
        change(stk2, stk1);

        return res;
    }
    
    public int peek() {
        change(stk1, stk2);
        int res = stk2.peekLast();
        change(stk2, stk1);

        return res;
    }
    
    public boolean empty() {
        return stk1.isEmpty() && stk2.isEmpty();
    }

    private void change(Deque<Integer> a, Deque<Integer> b){
        while (a.size() > 0){
            b.addLast(a.peekLast());
            a.removeLast();
        }
    }
}