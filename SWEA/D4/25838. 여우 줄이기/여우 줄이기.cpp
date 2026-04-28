# include <iostream>
# include <string>
using namespace std;

void solve(){
    int n;  cin >> n;
    string word;    cin >> word;
    string stack;
    stack.reserve(n);

    for (char let : word){
        int sz = stack.size();
        if (sz < 2){
            stack.push_back(let);
        }
        else if (let == 'x' && stack.substr(sz-2, 2) == "fo"){
            stack.pop_back();
            stack.pop_back();
            continue;
        }
        else {
            stack.push_back(let);
        }
    }

    cout << stack.size() << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int t;  cin >> t;
    while (t--){
        solve();
    }
}