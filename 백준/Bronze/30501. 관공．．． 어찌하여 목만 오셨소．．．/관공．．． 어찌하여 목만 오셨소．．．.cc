# include <iostream>
# include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    string ans;
    for (int i=0; i<n; i++){
        string name;    cin >> name;
        for (const char& letter : name){
            if (letter == 'S'){
                ans = name;
            }
        }
    }

    cout << ans;
}