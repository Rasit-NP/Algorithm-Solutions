# include <iostream>
# include <vector>
# include <string>
using namespace std;

vector<char> test;

bool check(){

    // for (char c : test){
    //     cout << c << ' ';
    // }
    // cout << endl;

    vector<char> stack;
    for (char c : test){
        if (stack.size() && c == ')' && stack.back() == '('){
            stack.pop_back();
            continue;
        }
        stack.push_back(c);
    }
    if (stack.size()){
        return false;
    }
    else {
        return true;
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    string s;   cin >> s;
    test.assign(n, 0);

    for (int i=0; i<(1<<n); i++){
        for (int j=0; j<n; j++){
            if (s[j] == 'G'){
                if (i & (1<<j)){
                    test[j] = '(';
                }
                else {
                    test[j] = ')';
                }
            }
            else {
                test[j] = s[j];
            }
        }
        if (check()){
            for (char c : test){
                cout << c;
            }
            return 0;
        }
    }
}