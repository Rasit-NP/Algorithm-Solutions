# include <string>
# include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char l : s){
            if (stk.size() == 0){
                stk.push(l);
            }
            else {
                if (l == ')' && stk.top() == '('){
                    stk.pop();
                }
                else if (l == '}' && stk.top() == '{'){
                    stk.pop();
                }
                else if (l == ']' && stk.top() == '['){
                    stk.pop();
                }
                else {
                    stk.push(l);
                }
            }
        }
        return stk.empty();
    }
};