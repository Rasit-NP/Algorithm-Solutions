# include <iostream>
# include <vector>
# include <string>
using namespace std;
 
void solve(){
    int n;  cin >> n;
    string word;    cin >> word;
 
    string newWord = "";
 
    for (const char let : word){
        if (newWord.size() && newWord.back() == let){
            continue;
        }
        newWord.push_back(let);
    }
 
    if (newWord.size() == 2){
        cout << "2\n";
    }
    else {
        cout << "1\n";
    }
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;  cin >> t;
    while (t--){
        solve();
    }
}