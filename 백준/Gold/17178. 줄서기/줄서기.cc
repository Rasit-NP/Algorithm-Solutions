# include <iostream>
# include <queue>
# include <string>
# include <stack>
using namespace std;

struct Code{
    char en;
    int num;

    Code(){
        this->en = 'A';
        this->num = 0;
    }

    Code(string code){
        this->en = code[0];
        this->num = stoi(code.substr(2, code.size()-2));
    }

    bool operator<(Code& code){
        if (this->en < code.en){
            return true;
        }
        else if (this->en == code.en && this->num < code.num){
            return true;
        }
        return false;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    queue<Code> line;
    stack<Code> wait;
    for (int i=0; i<n; i++){
        for (int j=0; j<5; j++){
            string code;    cin >> code;
            line.emplace(code);
        }
    }

    Code latest;
    bool res = true;

    while (line.size() || wait.size()){
        if (!wait.size()){
            wait.push(line.front());    line.pop();
            continue;
        }
        if (!line.size()){
            if (wait.top() < latest){
                res = false;
                break;
            }
            latest = wait.top();
            wait.pop();
            continue;
        }
        
        if (wait.top() < line.front()){
            if (wait.top() < latest){
                res = false;
                break;
            }
            latest = wait.top();
            wait.pop();
        }
        else if (line.front() < wait.top()){
            wait.push(line.front());    line.pop();
        }
    }

    if (res){
        cout << "GOOD";
    }
    else {
        cout << "BAD";
    }
}