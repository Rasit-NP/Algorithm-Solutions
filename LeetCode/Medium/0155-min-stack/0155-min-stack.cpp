# include <vector>
# include <map>
using namespace std;

class MinStack {
private:
    int* stk;
    int sz;
    map<int, int> cnt;
public:
    MinStack() {
        stk = (int*)malloc(sizeof(int)*30001);
        sz = 0;
    }
    
    void push(int val) {
        cnt[val]++;
        stk[sz++] = val;
    }
    
    void pop() {
        int val = stk[--sz];
        if (--cnt[val] == 0){
            cnt.erase(val);
        }
    }
    
    int top() {
        return stk[sz-1];
    }
    
    int getMin() {
        for (pair<const int, int>& data : cnt){
            return data.first;
        }

        return 0;
    }
};