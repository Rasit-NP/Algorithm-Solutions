# include <string>
# include <stack>

using namespace std;

bool solution(string s){
    bool answer;
    
    stack<char> stk;
    
    for (char let : s){
        if (stk.size() == 0 || let == '('){
            stk.push(let);
        }
        else if (let == ')' && stk.top() == '('){
            stk.pop();
        }
    }
    
    if (stk.size() == 0){
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
}