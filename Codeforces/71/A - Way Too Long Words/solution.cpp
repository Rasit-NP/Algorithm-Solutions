# include <iostream>
# include <string>
using namespace std;
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int n;  cin >> n;
    while (n--){
        string word;    cin >> word;
 
        if (word.size() <= 10){
            cout << word << '\n';
            continue;
        }
        else {
            cout << word[0] << word.size()-2 << word.back() << '\n';
        }
    }
}