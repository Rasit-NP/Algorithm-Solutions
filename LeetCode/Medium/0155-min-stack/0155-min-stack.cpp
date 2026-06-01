# include <vector>
# include <algorithm>
using namespace std;

class MinStack {
private:
    int* stk;
    int* mini;
    int sz;
public:
    MinStack() {
        stk = (int*)malloc(sizeof(int)*30001);
        mini = (int*)malloc(sizeof(int)*30001);
        sz = 0;
    }
    
    void push(int val) {
        if (sz){
            mini[sz] = min(mini[sz-1], val);
        }
        else {
            mini[sz] = val;
        }
        stk[sz++] = val;
    }
    
    void pop() {
        --sz;
    }
    
    int top() {
        return stk[sz-1];
    }
    
    int getMin() {
        return mini[sz-1];
    }
};