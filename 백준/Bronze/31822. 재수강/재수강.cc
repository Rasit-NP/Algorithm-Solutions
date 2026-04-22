# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string subject; cin >> subject;
    string cmp = subject.substr(0, 5);
    int n;  cin >> n;
    int res = 0;
    while (n--){
        string newSubject;  cin >> newSubject;
        if (cmp == newSubject.substr(0, 5)){
            ++res;
        }
    }
    cout << res;
}