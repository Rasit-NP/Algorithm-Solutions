# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    string ans;
    while (n--){
        string subject; cin >> subject;
        int year;   cin >> year;

        if (year == 2026){
            ans = subject;
        }
    }

    cout << ans;
}